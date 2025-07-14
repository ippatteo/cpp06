#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    std::cout << "=== Dynamic Cast Tests ===" << std::endl;
    
    // Test 1: Generate and identify multiple objects
    std::cout << "\n--- Test 1: Random Generation and Identification ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest " << (i + 1) << ":" << std::endl;
        Base* obj = generate();
        
        std::cout << "Pointer identification: ";
        identify(obj);
        
        std::cout << "Reference identification: ";
        identify(*obj);
        
        delete obj;
    }
    
    // Test 2: Specific object testing
    std::cout << "\n--- Test 2: Specific Object Testing ---" << std::endl;
    
    // Test A
    std::cout << "\nCreating A object:" << std::endl;
    Base* a = new A();
    std::cout << "Pointer identify: ";
    identify(a);
    std::cout << "Reference identify: ";
    identify(*a);
    delete a;
    
    // Test B
    std::cout << "\nCreating B object:" << std::endl;
    Base* b = new B();
    std::cout << "Pointer identify: ";
    identify(b);
    std::cout << "Reference identify: ";
    identify(*b);
    delete b;
    
    // Test C
    std::cout << "\nCreating C object:" << std::endl;
    Base* c = new C();
    std::cout << "Pointer identify: ";
    identify(c);
    std::cout << "Reference identify: ";
    identify(*c);
    delete c;
    
    // Test 3: Array of objects
    std::cout << "\n--- Test 3: Array of Objects ---" << std::endl;
    Base* objects[6];
    
    // Create array of mixed objects
    objects[0] = new A();
    objects[1] = new B();
    objects[2] = new C();
    objects[3] = new A();
    objects[4] = new B();
    objects[5] = new C();
    
    std::cout << "\nIdentifying array objects:" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << "Object " << i << " - Pointer: ";
        identify(objects[i]);
        std::cout << "Object " << i << " - Reference: ";
        identify(*objects[i]);
    }
    
    // Cleanup array
    for (int i = 0; i < 6; i++) {
        delete objects[i];
    }
    
    // Test 4: Null pointer test
    std::cout << "\n--- Test 4: Null Pointer Test ---" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Testing null pointer: ";
    identify(nullPtr);
    
    std::cout << "\n=== All Tests Completed ===" << std::endl;
    return 0;
}