/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:50:53 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/07 16:32:34 by ytouihar         ###   ########.fr       */
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

class Contact{
	private :
	std::string	phone_number{};
	std::string	first_name{};
	std::string	last_name{};
	std::string	nick_name{};
	std::string	darkest_secret{};
	int			index;
		
public :
	Contact();
	
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