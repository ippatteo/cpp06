#include "ScalarConverter.hpp"

int main(int argv, char **arga)
{
	if (argv != 2)
	{
		std::cout << "incorrect number of arguments!" << std::endl;
		return (0);
	}
	ScalarConverter::convert(arga[1]);
	return 0;
}
