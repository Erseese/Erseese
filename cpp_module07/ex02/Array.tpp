/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:48:22 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:51 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
template <typename T>
Array<T>::Array()
{
    std::cout << "Default constructeur called" << std::endl;
	this->_array = nullptr;
	this->_length = 0;
}
template <typename T>
Array<T>::Array(T arr, unsigned int length) 
{
	std::cout << "constructeur" << std::endl;
	
	this->_array = new (arr);
	for (int i = 0; length > i; i++)
		_array[i] = T();
	this->_length = length;
}
template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructeur" << std::endl;
	delete[] this->_array;
}
template <typename T>
Array<T>::Array<T>(const Array<T> &test)
{
	this->_array = new (T[]);
	for (int i = 0; i < test._length; i++;)
		this->_array[i] = test._array[i];
	this->_length = test._length;
}
template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &egal)
{    
    if (this != &egal)
    {
		delete[] this->_array;
		new T[];
        for (int i = 0; i < egal._length; i++;)
			this->_array[i] = egal._array[i];
        this->_length = egal._length;
    }
    return (*this);
}
template <typename T>
const char *Array<T>::GradeTooLowException::what() const throw()
{
    return ("ptit flop de ta part tu feras mieux la prochaien fois pas bon index\n");
}
template <typename T>
T &Array<T>::operator[](Array const &i)
{
	if (index < 0 || index > this->_length)
		throw (Array::GradeTooLowException());
	return (this->_array[i]);
}