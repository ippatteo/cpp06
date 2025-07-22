#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Inizializza il seed per i numeri casuali
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    std::cout << "=== Test Dynamic Cast ===" << std::endl;
    
    // Test 1: Generazione casuale e identificazione
    std::cout << "\n--- Test Generazione Casuale ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "\nOggetto " << (i + 1) << ":" << std::endl;
        Base* obj = generate();
        
        std::cout << "Identificazione con puntatore: ";
        identify(obj);
        
        std::cout << "Identificazione con reference: ";
        identify(*obj);
        
        delete obj;
    }
    std::cout << "\n--- Test Tipi Specifici ---" << std::endl;
    
    // Test A
    std::cout << "\nCreo oggetto di tipo A:" << std::endl;
    Base* a = new A();
    std::cout << "Con puntatore: ";
    identify(a);
    std::cout << "Con reference: ";
    identify(*a);
    delete a;
    // Test B
    std::cout << "\nCreo oggetto di tipo B:" << std::endl;
    Base* b = new B();
    std::cout << "Con puntatore: ";
    identify(b);
    std::cout << "Con reference: ";
    identify(*b);
    delete b;
    // Test C
    std::cout << "\nCreo oggetto di tipo C:" << std::endl;
    Base* c = new C();
    std::cout << "Con puntatore: ";
    identify(c);
    std::cout << "Con reference: ";
    identify(*c);
    delete c;
    
    // Puntatore NULL
    std::cout << "\n--- Test Puntatore NULL ---" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Test con puntatore NULL: ";
    identify(nullPtr);
    
    std::cout << "\n=== Test Completati ===" << std::endl;
    return 0;
}