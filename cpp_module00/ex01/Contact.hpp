/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ersees <ersees@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:53 by ytouihar          #+#    #+#             */
/*   Updated: 2024/03/22 20:42:11 by ersees           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cstdio>

class Contact{
	private :
	std::string	phone_number;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	darkest_secret;
	int			index;
		
public :
	Contact() : phone_number(""), first_name(""), last_name(""), nick_name(""), darkest_secret(""), index(0) {}
	
	void	fill_firstname(void);
	void	fill_lastname(void);
	void	fill_phonenumber(void);
	void	fill_nickname(void);
	void	fill_darkest_secret(void);
	void	fill_index(int indexs);
	void	print_lastname(int i);
	void	print_everythingtest(void);
};

#endif