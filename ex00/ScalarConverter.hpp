#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cerrno>


class ScalarConverter {
	private:
		ScalarConverter();
		virtual ~ScalarConverter() = 0;
	public:
		static void convert(const std::string &words);
};

#endif