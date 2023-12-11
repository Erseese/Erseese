/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:27 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 15:03:52 by ytouihar         ###   ########.fr       */
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

};

std::ostream & operator<<(std::ostream & yey, Fixed const & tsst);

#endif