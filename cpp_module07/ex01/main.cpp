/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:15:57 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/19 17:46:48 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T , typename Tl>
void	iter(T *addr, Tl const length,void (*fct)(T&))
{
	for (Tl i = 0; length > i; i++)
		fct(addr[i]);
}

#include <iostream>

void	print(int& n) {
	std::cout << n << std::endl;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	long len = sizeof(arr) / sizeof(int);
	iter(arr, len, print);
	return 0;
}