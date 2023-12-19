/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:16:57 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/19 15:37:23 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "construction" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "destruction" << std::endl;
}
/*static std::string	definePrecType(std::string input, int* float_prec, int* double_prec)
{
	std::string inf_nan = "undef";
	int len = input.length();
	if ((len == 3 && ((input.compare("nan") == 0) || (input.compare("inf") == 0)))
		|| (len == 4 && (input.compare("+inf") == 0 || input.compare("-inf") == 0)))
		return input;
}*/

static void	printint(std::string value)
{
	char valuechar;
	int value1;
	float value2;
	double value3;
	std::stringstream ss;

	ss << value;
	ss >> value1;
	valuechar = static_cast<char>(value1);
	value3 = static_cast<double>(value1);
	value2 = static_cast<float>(value1);
	if (value1 > 126 || value1 < 31)
	std::cout << "char : nonprintable" << std::endl;
	else
		std::cout << "char : " << valuechar << std::endl;
	std::cout << "int : " << value1 << std::endl;
	std::cout << "float : " << value2 << "f" << std::endl;
	std::cout << "double : " << value3 << std::endl;
}
static void printfloat(std::string value)
{
	char valuechar;
	int value1;
	float value2;
	double value3;
	std::stringstream ss;

	ss << value;
	ss >> value2;
	valuechar = static_cast<char>(value2);
	value1 = static_cast<int>(value2);
	value3 = static_cast<double>(value2);
	if (value1 > 126 || value1 < 31)
		std::cout << "char : nonprintable" << std::endl;
	else
		std::cout << "char : " << valuechar << std::endl;
	std::cout << "int : " << value1 << std::endl;
	std::cout << "float : " << value2 << "f" << std::endl;
	std::cout << "double : " << value3 << std::endl;
}
static void printdouble(std::string value)
{
	char valuechar;
	int value1;
	float value2;
	double value3;
	std::stringstream ss;
	
	ss << value;
	ss >> value3;
	valuechar = static_cast<char>(value3);
	value1 = static_cast<int>(value3);
	value2 = static_cast<float>(value3);
	if (value1 > 126|| value1 < 31)
		std::cout << "char : nonprintable" << std::endl;
	else
		std::cout << "char : " << valuechar << std::endl;
	std::cout << "int : " << value1 << std::endl;
	std::cout << "float : " << value2 << "f" << std::endl;
	std::cout << "double : " << value3 << std::endl;
}
static void printchar(std::string value)
{
	char valuechar;
	int value1;
	float value2;
	double value3;
	std::stringstream ss;

	ss << value;
	ss >> valuechar;//methode to tranforme string into char
	value3 = static_cast<double>(valuechar);
	value1 = static_cast<int>(valuechar);
	value2 = static_cast<float>(valuechar);
	if (value1 > 126 || value1 < 31)
		std::cout << "char : nonprintable" << std::endl;
	else
		std::cout << "char : " << valuechar << std::endl;
	std::cout << "int : " << value1 << std::endl;
	std::cout << "float : " << value2 << "f" << std::endl;
	std::cout << "double : " << value3 << std::endl;
}
void ScalarConverter::convert(std::string literal)
{
	//check args if its char/double/float/int
	int t = 3;
	switch (t)
	{
		case CHAR:
			//statement char;
			printchar(literal);
			break;
		case INT:
			//statement int;
			printint(literal);
			break;
		case FLOAT:
			printfloat(literal);
			break;
			//statement float
		case DOUBLE:
			printdouble(literal);
			break;
			//statement double
	}
}

ScalarConverter::ScalarConverter(const ScalarConverter &test)
{
	*this = test;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &egal)
{
	(void)egal;
	return (*this);
}