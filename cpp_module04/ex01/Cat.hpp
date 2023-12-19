/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:23:20 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 16:45:07 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public :
	Cat();
	Cat(std::string type);
	virtual ~Cat();
	Cat(Cat const &copy);
	Cat &operator=(Cat const &egal);

	virtual void makeSound() const;
};

#endif