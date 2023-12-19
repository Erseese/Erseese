/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:29:11 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/15 16:16:38 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	private : 
	Brain *_brain;

	public :
	Dog();
	Dog(std::string type);
	virtual ~Dog();
	Dog(Dog const &copy);
	Dog &operator=(Dog const &egal);

	virtual void makeSound() const;
};

#endif