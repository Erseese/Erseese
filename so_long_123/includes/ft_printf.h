/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:45:24 by ytouihar          #+#    #+#             */
/*   Updated: 2023/11/10 12:45:25 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_taille(unsigned long int nb, unsigned long int base);
char	*ft_itoa(unsigned long int nb, unsigned long int base);
char	*ft_itoa_maj(unsigned long int nb, unsigned long int base);
int		ft_printp(unsigned long int l);
int		ft_printd(int l);
int		ft_printu(unsigned int l);
int		ft_printx(unsigned int z);
int		ft_printxc(unsigned int z);
int		choix_fonct(va_list ptr, const char *d);
int		ft_printf(const char *d, ...);
char	*ft_itoa2(long int nb, long int base);
int		ft_taille2(long int nb, long int base);

#endif