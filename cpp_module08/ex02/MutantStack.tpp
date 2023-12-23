/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:17:36 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/23 17:42:17 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "constructeur" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destructeur" << std::endl;
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &test)
{
	*this = test;
}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &egal)
{	
	if (this != &egal)
		this->_stack = egal._stack;
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void )
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void )
{
	return (this->c.end());
}