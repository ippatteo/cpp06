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

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	beta;

	beta = reinterpret_cast<uintptr_t>(ptr);
	return (beta);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data*	alpha;

	alpha = reinterpret_cast<Data*>(raw);

	return (alpha);
}

