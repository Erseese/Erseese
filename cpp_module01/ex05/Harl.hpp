/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:19:52 by ersees            #+#    #+#             */
/*   Updated: 2023/12/11 11:14:58 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private :
	void _debug (void);
	void _info(void);
	void _warning(void);
	void _error(void);

	public :
	Harl();
	~Harl();
	void	complain(std::string level);
	
};

#endif