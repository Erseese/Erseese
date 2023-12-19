/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:43 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 14:50:12 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
	WrongCat();
	WrongCat(std::string type);
	~WrongCat();
	WrongCat(WrongCat const &copy);
	WrongCat &operator=(WrongCat const &egal);

	void makeSound() const;
};

#endif