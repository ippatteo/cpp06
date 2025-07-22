#include "Serializer.hpp"


Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer &)
{
}

Serializer& Serializer::operator=(const Serializer&)
{
	return *this;
}

/*
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(Data* ptr);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data* deserialize(uintptr_t raw);
*/
// beta = (uintptr_t)((void*)ptr);

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	beta;

	beta = reinterpret_cast<uintptr_t>((void*)ptr);
	return (beta);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data*	alpha;

	alpha = reinterpret_cast<Data*>(raw);

	return (alpha);
}

