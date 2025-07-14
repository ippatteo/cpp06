#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}
Base* generate()
{
	switch ( rand() % 3 )
	{
	  case 0: 
	  	return new A();
	  case 1: 
	  	return new B();
	  default: 
	  	return new C();
	}
}

/*
dynamic cast se ha come "parametro" un puntatore, ritorna un puntatore
NULL quindi si puo mettere in un if esle
*/
void identify(Base* p)
{
		A*	checker1;
		B*	checker2;
	
		if ((checker1 = dynamic_cast<A*>(p)))
			std::cout<<"Type A"<<std::endl;
		else if ((checker2 = dynamic_cast<B*>(p)))
			std::cout<<"Type B"<<std::endl;
		else
			std::cout<<"Type C"<<std::endl;
	
}


/*
il dynamic cast se usa una reference che va male
 lancia l'errore std::bad_cast
*/
void identify(Base& p)
{
	try
	{
		A& checker1 = dynamic_cast<A&>(p);
		std::cout<<"Type A"<<std::endl;
		(void)checker1; //evita warning
	}
	catch(const std::exception& e)
	{
		try
		{
			B& checker2 = dynamic_cast<B&>(p);
			std::cout<<"Type B"<<std::endl;
			(void)checker2;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& checker3 = dynamic_cast<C&>(p);
				std::cout<<"Type C"<<std::endl;
				(void)checker3;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

	}
}
