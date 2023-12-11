/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:29 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 12:17:59 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed()
{
	this->_fixedpoint = 0;
	std::cout << "construction" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destruction boooom" << std::endl;
}
Fixed::Fixed(const Fixed &test)
{
	this->_fixedpoint = test.getRawBits();
}

Fixed	&Fixed::operator=(Fixed const & tst)
{
	std::cout << "operator called" << std::endl;
	this->_fixedpoint = tst.getRawBits();

	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getrawbits" << std::endl;
	return (this->_fixedpoint);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setrawbits" << std::endl;
	this->_fixedpoint = raw;
}