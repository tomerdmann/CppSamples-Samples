// Singleton

class Singleton {
public:
    static Singleton* get_instance();

    // Disable copy/move construction/assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator= (const Singleton&&) = delete;

private:
    Singleton();    // Private constructor
    ~Singleton();   // Prevents accidental deletion

    static Singleton* ptr;
};

Singleton* Singleton::ptr = nullptr;

Singleton::Singleton() {
    // Construct
}

Singleton* Singleton::get_instance() {
    if (!ptr) {
        ptr = new Singleton();
    }
    return ptr;
}


int main() {
    auto x = Singleton::get_instance();
    return 0;
}

// Unique, globally-accessible objects
//
// Sometimes you need exactly one instance of a class, globally accessible,
//
// The private contstructor guarantees that no instances of the class may be created
// outside of the class methods. Internally, the get_instance() method guarantees that
// only one instance of Singleton is ever used.
//
// A single static pointer is used to maintain jjjkkk
// Notably, the copy/move constructors/operators have been disapbled.
// This is to explicitly preserve the

