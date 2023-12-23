/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:27:19 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/23 16:07:02 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <vector>
#include <algorithm>

class Span{

public :
    Span();
    Span(unsigned int _N);
    ~Span();
    void    addNumber(int unsigned const toadd);
    int		shortestSpan(void);
	int	longestSpan();
    Span(const Span &test);
    Span &operator=(Span const &egal);
    class LessThenTwo : public std::exception {
    public :
        virtual const char* what() const throw();
    };
class TooMuchThings : public std::exception {
    public :
        virtual const char* what() const throw();
};
template <typename T>
void addNumbers(T begin, T end);

private :
	std::vector<int> _Numbers;
    unsigned int    _N;

};
#endif