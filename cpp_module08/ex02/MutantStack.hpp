/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:53:15 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/23 17:44:13 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <iterator>
template <typename T>

class MutantStack : public std::stack<T> {

public :
    MutantStack<T>();
    ~MutantStack();
    MutantStack(const MutantStack<T> &test);
    MutantStack &operator=(MutantStack<T> const &egal);
	
	typedef	typename	std::stack<T>::container_type::iterator	iterator;
	iterator		begin( void );
	iterator		end( void );
private :
};
#endif