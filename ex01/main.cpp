#include  "Serializer.hpp"


/*
int main()
{
	int i[2];
	int c = 5;
	//int a;

	//a = &i;
	//std::cout << a << std::endl;
	std::cout << reinterpret_cast<uintptr_t>(i) << std::endl;
	unsigned long b = static_cast<unsigned long>(reinterpret_cast<uintptr_t>(i));
	std::cout << &i << std::endl;
	std::cout << b << std::endl;
	return 0;
}

uintptr_t serve a conservare in decimale l'esadecimale di puntatori, in modo
che diventi un "numero" conservabile e gestibile.

reinterpret_cast prende il valore in bit di un’espressione 
e lo interpreta come un tipo diverso.

è riservato a conversioni di 
puntatori/referenze o tra puntatori e interi.
*/


#include "Serializer.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Serializer Tests ===" << std::endl;
    
    // Test 1: Basic serialization and deserialization
    std::cout << "\n--- Test 1: Basic Functionality ---" << std::endl;
    Data* original = new Data;
    original->x = 42;
    original->y = 3.14f;
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << original << std::endl;
    std::cout << "  x: " << original->x << std::endl;
    std::cout << "  y: " << original->y << std::endl;
    
    // Serialize
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "\nSerialized to uintptr_t: " << serialized << std::endl;
    
    // Deserialize
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  x: " << deserialized->x << std::endl;
    std::cout << "  y: " << deserialized->y << std::endl;
    
    // Test if addresses match
    std::cout << "\nAddress comparison:" << std::endl;
    if (original == deserialized)
        std::cout << "  Original == Deserialized: YES" << std::endl;
    else
        std::cout << "  Original == Deserialized: NO" << std::endl;
    
    // Test 2: Multiple objects
    std::cout << "\n--- Test 2: Multiple Objects ---" << std::endl;
    Data* data1 = new Data;
    data1->x = 100;
    data1->y = 1.23f;
    
    Data* data2 = new Data;
    data2->x = 200;
    data2->y = 4.56f;
    
    uintptr_t ser1 = Serializer::serialize(data1);
    uintptr_t ser2 = Serializer::serialize(data2);
    
    std::cout << "Data1 address: " << data1 << " -> serialized: " << ser1 << std::endl;
    std::cout << "Data2 address: " << data2 << " -> serialized: " << ser2 << std::endl;
    
    Data* deser1 = Serializer::deserialize(ser1);
    Data* deser2 = Serializer::deserialize(ser2);
    
    std::cout << "Deserialized1: " << deser1 << " (x=" << deser1->x << ", y=" << deser1->y << ")" << std::endl;
    std::cout << "Deserialized2: " << deser2 << " (x=" << deser2->x << ", y=" << deser2->y << ")" << std::endl;
    
    // Test 3: Stack allocated object
    std::cout << "\n--- Test 3: Stack Object ---" << std::endl;
    Data stackData;
    stackData.x = 999;
    stackData.y = 7.89f;
    std::cout << "Stack Data address: " << &stackData << std::endl;
    
    uintptr_t stackSer = Serializer::serialize(&stackData);
    Data* stackDeser = Serializer::deserialize(stackSer);
    
    std::cout << "Stack serialized: " << stackSer << std::endl;
    std::cout << "Stack deserialized: " << stackDeser << std::endl;
    if (stackDeser->x == stackData.x && stackDeser->y == stackData.y)
        std::cout << "Values match: YES" << std::endl;
    else
        std::cout << "Values match: NO" << std::endl;
    
    // Test 4: Null pointer
    std::cout << "\n--- Test 4: Null Pointer ---" << std::endl;
    Data* nullPtr = NULL;
    uintptr_t nullSer = Serializer::serialize(nullPtr);
    Data* nullDeser = Serializer::deserialize(nullSer);
    
    std::cout << "Null serialized: " << nullSer << std::endl;
    std::cout << "Null deserialized: " << nullDeser << std::endl;
    if (nullPtr == nullDeser)
        std::cout << "Both null: YES" << std::endl;
    else
        std::cout << "Both null: NO" << std::endl;
    
    // Test 5: Round trip test
    std::cout << "\n--- Test 5: Round Trip Test ---" << std::endl;
    Data* roundTrip = new Data;
    roundTrip->x = 777;
    roundTrip->y = 2.71f;
    std::cout << "Original: " << roundTrip << std::endl;
    
    for (int i = 0; i < 3; i++) {
        uintptr_t temp = Serializer::serialize(roundTrip);
        roundTrip = Serializer::deserialize(temp);
        std::cout << "Round " << (i + 1) << ": " << roundTrip << std::endl;
    }
    
    // Cleanup
    delete original;
    delete data1;
    delete data2;
    delete roundTrip;
    
    std::cout << "\n=== All Tests Completed ===" << std::endl;
    return 0;
}