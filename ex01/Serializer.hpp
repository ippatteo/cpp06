#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cerrno>
#include <stdint.h>
#include "Data.hpp"


class Serializer {
	private:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(const Serializer &);
		Serializer& operator=(const Serializer&);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};