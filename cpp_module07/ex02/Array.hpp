/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:48:12 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/19 19:11:33 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
template <typename T>
class Array{

public :
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array &test);
	Array &operator=(Array const &egal);
	class GradeTooHighException : public std::exception {
    public :
        virtual const char* what() const throw();
    };
	T &operator[](Array const &i);

private :
	T	_array;
	unsigned int	_length;

};
#endif