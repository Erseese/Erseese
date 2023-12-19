/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:12:36 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/15 16:16:21 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

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
	void	printIdeas(void) const;
};

#endif