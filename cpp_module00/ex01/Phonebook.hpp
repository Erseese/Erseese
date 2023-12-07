/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:21:05 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/07 17:02:08 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"


class Phonebook {
	private :
	Contact ctontact[8];
	int	index;
	int	nmbrdeadd;

	public :
	Phonebook() : index(0), nmbrdeadd(0) {}
	
	int		isnum(const std::string &str);
	void	fillcontact(int index, int nmbrdeadd);
	void	search(void);
};

#endif