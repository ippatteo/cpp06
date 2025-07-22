#ifndef BASE_HPP
#define BASE_HPP



#include <iostream>
#include <string>
#include <cmath>
#include <cerrno>
#include <stdint.h>


class Base {
	public:
		virtual ~Base() = 0;
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
