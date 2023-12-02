/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:33:20 by ytouihar          #+#    #+#             */
/*   Updated: 2023/12/01 17:59:42 by ytouihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choix_fonct(va_list ptr, const char *d)
{
	int	len;

	len = 0;
	d++;
	if (*d == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (*d == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (*d == 'p')
		len += ft_printp(va_arg(ptr, unsigned long int));
	else if (*d == 'd')
		len += ft_printd(va_arg(ptr, int));
	else if (*d == 'i')
		len += ft_printd(va_arg(ptr, int));
	else if (*d == 'u')
		len += ft_printu(va_arg(ptr, unsigned int));
	else if (*d == 'x')
		len += ft_printx(va_arg(ptr, int));
	else if (*d == 'X')
		len += ft_printxc(va_arg(ptr, int));
	else if (*d == '%')
		len += ft_putchar('%');
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *d, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	if (d == NULL)
		return (0);
	va_start(ptr, d);
	while (*d)
	{
		if (*d == '%')
		{
			len += choix_fonct(ptr, d);
			if (len == -1)
				return (0);
			d += 2;
		}
		else
		{
			write(1, d, 1);
			d++;
			len++;
		}
	}
	va_end(ptr);
	return (len);
}
/*int main()
{
	//ft_print("tesddsas %csdaiudsahu%s", 'a', "test");
    //printf("3 %s ", test("uwu", "test", "ewew"));
	//int lll = 10;
	//void *test = &lll;
	
	printf("\ntest pour le %%d\n\n");
    int l = ft_printf("ma printf : sadasdsddsad \\  %dtest",2147483647);
	printf("  \\ int ma printf : %d\n", l);
	int t = printf("la printf : sadasdsddsad \\  %dtest",2147483647);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		int min:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %dtest",-2147483648);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %dtest",-2147483648);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		0:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %dtest",0);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %dtest",0);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		154650:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %dtest",154650);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %dtest",154650);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		-21540:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %dtest",-21540);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %dtest",-21540);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	
	printf("\ntest pour le %%i \n\n");
	printf("\n\n		int max:\n");
     l = ft_printf("ma printf : sadasdsddsad \\  %itest",2147483647);
	printf("  \\ int ma printf : %d\n", l);
	 t = printf("la printf : sadasdsddsad \\  %itest",2147483647);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		int min:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %itest",-2147483648);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %itest",-2147483648);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		0:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %itest",0);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %itest",0);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		154650:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %itest",154650);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %itest",154650);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		-21540:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %itest",-21540);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %itest",-21540);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\ntest pour le %%c \n\n");
	printf("\n\n		char max:\n");
     l = ft_printf("ma printf : sadasdsddsad \\  %ctest",127);
	printf("  \\ int ma printf : %d\n", l);
	 t = printf("la printf : sadasdsddsad \\  %ctest",127);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		char min:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %ctest",-128);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %ctest",-128);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		0:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %ctest",0);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %ctest",0);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		a:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %itest",'a');
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %itest",'a');
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		0:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %itest",'0');
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %itest",'0');
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\ntest pour le %%s \n\n");
	char	basique[] = "jesaispas";

	printf("\n\n		trucbasique:\n");
     l = ft_printf("ma printf : sadasdsddsad \\  %stest", basique);
	printf(" int ma printf : %d\n", l);
	 t = printf("la printf : sadasdsddsad \\  %stest", basique);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		vide:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %stest","");
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %stest","");
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		NULL:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %sdsad",0);
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %sdsad",0);
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		random chain:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %stest","-4832166");
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %stest","-4832166");
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	printf("\n\n		single character:\n");
	l = ft_printf("ma printf : sadasdsddsad \\  %stest","y");
	printf("  \\ int ma printf : %d\n", l);
	t = printf("la printf : sadasdsddsad \\  %stest","y");
	printf("  \\ int la printf : %d", t);
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
	//ft_printf("test yanis :%p", 9223372036854775807);
	//printf("\ntest dsadd :%p", 9223372036854775807);

	//ft_printf("\ntest yanis%p", LONG_MAX);
	//printf("\n   test %p", LONG_MAX);
	
	int l = ft_printf("\ntest yanis%p", LONG_MIN);
	printf("  \\ int ma printf : %d\n", l);
	int t = printf("\ntest yanis%p", LONG_MIN);
	printf("  \\ int la printf : %d\n", t);
	
	if (l == t)
		printf("\nOK");
	else
	{
		printf("\nERROR");
		return (0);
	}
    return 0;
	printf("test %x\n", -568151335);
	ft_printf("test %x\n", -568151335);
}*/