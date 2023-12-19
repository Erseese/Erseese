/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:17:01 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/19 14:21:00 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

class ScalarConverter{

public :
static void convert(std::string literal);

private :
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &test);
	ScalarConverter &operator=(ScalarConverter const &egal);
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &ScalarConverter);

#endif