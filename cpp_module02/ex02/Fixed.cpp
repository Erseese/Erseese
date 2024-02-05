/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:29 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 23:11:20 by ersees           ###   ########.fr       */
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
	*this = test;
}

Fixed::Fixed(const float numb)
{
	this->_fixedpoint = roundf((numb * (1 << this->_bits)));
}

Fixed::Fixed(const int num)
{
	this->_fixedpoint = (num << 8);
}

Fixed	&Fixed::operator=(Fixed const & tst)
{
	std::cout << "operator called = " << std::endl;
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

int Fixed::toInt( void ) const
{
	return (this->_fixedpoint >> this->_bits);
}

float Fixed::toFloat( void ) const
{
	return (float)((this->_fixedpoint) / (float)(1 << this->_bits));
}

std::ostream &operator<<(std::ostream & yey, Fixed const & tsst)
{
	std::cout << "operator << called" << std::endl;
	yey << tsst.toFloat();
	return yey;
}

Fixed Fixed::operator+(const Fixed &plus) const
{
	return (this->_fixedpoint + plus.getRawBits());
}

Fixed Fixed::operator-(const Fixed &moins) const
{
	return (this->_fixedpoint - moins.getRawBits());
}

Fixed	Fixed::operator*(const Fixed &mult) const
{
	return (Fixed(mult.toFloat() * this->toFloat()));
}

Fixed	Fixed::operator/(const Fixed &div) const
{
	return (Fixed(div.toFloat() * this->toFloat()));
}

int	Fixed::operator>(Fixed const &pgq) const
{
	if (this->_fixedpoint > pgq.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator<(Fixed const &ppq) const
{
	if (this->_fixedpoint < ppq.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator<=(Fixed const & ppq) const
{
	if (this->_fixedpoint <= ppq.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator>=(Fixed const & pgq) const
{
	if (this->_fixedpoint >= pgq.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator!=(Fixed const & pgq) const
{
	if (this->_fixedpoint != pgq.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator==(Fixed const & pgq) const
{
	if (this->_fixedpoint == pgq.getRawBits())
		return (1);
	return (0);
}

Fixed	&Fixed::operator--()
{
	this->_fixedpoint -= 1;
	return *this;
}

Fixed	&Fixed::operator++()
{
	(this->_fixedpoint)++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = Fixed(*this);
	this->_fixedpoint += 1;
	return(temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = Fixed(*this);
	this->_fixedpoint -= 1;
	return(temp);
}


Fixed	Fixed::min(Fixed &s1, Fixed &s2)
{
	if (s1 > s2)
		return (s2);
	return (s1);
}

Fixed	Fixed::min(const Fixed &s1, const Fixed &s2)
{
	if (s1 > s2)
		return (s2);
	return (s1);
}

Fixed	Fixed::max(Fixed &s1, Fixed &s2)
{
	if (s1 >= s2)
		return (s1);
	return (s2);
}

Fixed	Fixed::max(const Fixed &s1, const Fixed &s2)
{
	if (s1 >= s2)
		return (s1);
	return (s2);
}