/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:36 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 16:47:34 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
	std::string _type;

	public :
	Animal();
	virtual ~Animal();
	Animal(Animal const &copy);
	std::string gettype() const;
	Animal &operator=(Animal const &egal);

	virtual void makeSound() const;
};

#endif