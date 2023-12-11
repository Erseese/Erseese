/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:27 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/11 12:17:32 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private :
	int _fixedpoint;
	static const int _bits;

	public : 
	Fixed();
	~Fixed();
	Fixed(const Fixed &test);

	Fixed & operator=(Fixed const & tst);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif