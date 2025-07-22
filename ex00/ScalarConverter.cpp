#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &words)
{
	float t;
	double n;
	int i;
	char s;
	//std::cout << words.size() << std::endl;
	if (words.size() == 1 && words.c_str()[0] > 32 && words.c_str()[0] < 127 && !(words.c_str()[0] >= '0' && words.c_str()[0] <= '9')) //&& words[0] == '\'' && words[2] == '\'')
	{
		s = words[0];
		n = static_cast<double>(s);
		t = static_cast<float>(n);
		i = static_cast<int>(s);
	}
	else if (words == "nan")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
		return;
	}
	else if (words == "nanf")
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
		return;
	}
	else if (words == "inf" || words == "inff")
	{
		n = HUGE_VAL;
		t = static_cast<float>(n);
		n = static_cast<float>(n);
		i = static_cast<int>(t);
		s = static_cast<char>(i);
	}
	else if (words == "-inf" || words == "-inff")
	{
		n = -HUGE_VAL;
		t = static_cast<float>(n);
		n = static_cast<float>(n);
		i = static_cast<int>(t);
		s = static_cast<char>(i);
	}
	else if (words[words.size()-1] == 'f')
	{
		n = std::atof(words.c_str());
		t = static_cast<float>(n);
		n = static_cast<float>(n);
		i = static_cast<int>(t);
		s = static_cast<char>(i);
	}
	else
	{
		n = std::atof(words.c_str());
		t = static_cast<float>(n);
		i = static_cast<int>(t);
		s = static_cast<char>(i);
	}
	if (n == 0 && words[0] != 48)
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: impossible" << std::endl;
		std::cout << "Double: impossible" << std::endl;
		return;
	}
	double m = std::floor(n);
	//stampa char
	std::cout << "Char: ";
	//debug
	//std::cout << "debug -----> n:"<< n << " m: " << m << std::endl;
	if ( n > 127 || m != n || n < 0)
	std::cout << "impossible" << std::endl;
	else if (n > 32 && n < 127)
	std::cout << "\'" << s << "\'" << std::endl;
	else 
	std::cout << "non displayable" << std::endl;
	//stampa int
	if (n > 2147483647 || n < -2147483648)
	std::cout << "Int: impossible" << std::endl;
	else
	std::cout << "Int: " << t << std::endl;
	//stampa float
	std::cout << "Float: " << t;
	float g = std::floor(t);
	if (g == t && !std::isinf(t) && (t < 1000000))
		std::cout << ".0";
	std::cout <<"f" << std::endl;
	//stampa double
	std::cout << "Double: " << n;
	if (m == n && !std::isinf(n) && (t < 1000000))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}
