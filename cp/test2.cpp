#include <iostream>
using namespace std;
class MyClass {
private:
    bool initialized;
    int data;

public:
    // Default constructor with initialization
    MyClass(int value) : data(value), initialized(true) {
        cout << "called\n";
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        if (!other.initialized) {
            std::cerr << "Error: Attempted to copy an uninitialized object!" << std::endl;
            exit(1);
        }
        data = other.data;
        initialized = other.initialized;
    }
    
    void showData() const {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    MyClass obj1(42);       // Properly initialized
    MyClass obj2 = obj1;    // Copy construction allowed
    obj2.showData();

    return 0;
}
