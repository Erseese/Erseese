/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:21:52 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/12 16:58:51 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private :
	std::string _ideas[100];

	public :
	Brain();
    ~Brain();
    Brain(const Brain &test);
    Brain &operator=(Brain const &egal);

	void	printFirstIdeas(void) const;
};

#endif