/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:27 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 18:33:26 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private :
	int _fixedpoint;
	static const int _bits;

	public : 
	Fixed();
	~Fixed();
	Fixed(const Fixed &test);
	Fixed(const float numb);
	Fixed(const int num);

	Fixed & operator=(Fixed const & tst);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
	int toInt( void ) const;
	float toFloat( void ) const;

	Fixed	operator+(Fixed const & plus) const;
	Fixed	operator-(Fixed const & moins) const;
	Fixed	operator*( const Fixed &mult ) const;
	Fixed	operator/( const Fixed &div ) const;

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	
	int	operator>(Fixed const & pgq) const;
	int	operator<(Fixed const & ppq) const;
	int	operator<=(Fixed const & ppq) const;
	int	operator>=(Fixed const & pgq) const;
	int	operator!=(Fixed const & notequal) const;
	int	operator==(Fixed const & equal) const;

	static Fixed	min(Fixed &s1, Fixed &s2);
	static Fixed	max(Fixed &s1, Fixed &s2);	
	static Fixed	min(const Fixed &s1, const Fixed &s2);
	static Fixed	max(const Fixed &s1, const Fixed &s2);

};

std::ostream & operator<<(std::ostream & yey, Fixed const & tsst);

#endif