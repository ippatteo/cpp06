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

#include "Serializer.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test Serializer ===" << std::endl;
    
    // Crea un oggetto Data
    Data* originale = new Data;
    originale->x = 42;
    originale->y = 3.14f;
    
    std::cout << "Dati originali:" << std::endl;
    std::cout << "  Indirizzo: " << originale << std::endl;
    std::cout << "  x = " << originale->x << ", y = " << originale->y << std::endl;
    
    // Serializza: puntatore -> numero
    uintptr_t serializzato = Serializer::serialize(originale);
    std::cout << "\nNumero serializzato: " << serializzato << std::endl;
    
    // Deserializza: numero -> puntatore
    Data* risultato = Serializer::deserialize(serializzato);
    std::cout << "\nDati deserializzati:" << std::endl;
    std::cout << "  Indirizzo: " << risultato << std::endl;
    std::cout << "  x = " << risultato->x << ", y = " << risultato->y << std::endl;
    
    // Controlla se ha funzionato
    if (originale == risultato)
        std::cout << "\nSUCCESSO: Gli indirizzi corrispondono!" << std::endl;
    else
        std::cout << "\nFALLITO: Gli indirizzi non corrispondono!" << std::endl;
    
    // Test con puntatore NULL
    std::cout << "\n--- Test NULL ---" << std::endl;
    Data* ptrNull = NULL;
    uintptr_t nullSerializzato = Serializer::serialize(ptrNull);
    Data* nullRisultato = Serializer::deserialize(nullSerializzato);
    
    if (ptrNull == nullRisultato)
        std::cout << "Test NULL superato" << std::endl;
    else
        std::cout << "Test NULL fallito" << std::endl;
    
    delete originale;
    return 0;
}