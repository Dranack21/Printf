/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:38:43 by habouda           #+#    #+#             */
/*   Updated: 2024/06/07 17:52:27 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_after(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (str[1] && str[1] == 'c')
	{
		ft_putchar(va_arg(args, int));
		return (1);
	}
	if (str[1] && (str[1] == 'x'))
		i = i + ft_hexa_lower(va_arg(args, int));
	else if (str[1] && (str[1] == 'X'))
		i = i + ft_hexa_upper(va_arg(args, long));
	else if (str[1] && (str[1] == 'd' || str[1] == 'i'))
		i = i + ft_putnbr(va_arg(args, int));
	else if (str[1] == 'u')
		i = i + ft_putunbr(va_arg(args, int));
	else if (str[1] && str[1] == 's')
		i = i + ft_putstr(va_arg(args, char *));
	else if (str[1] && str[1] == '%')
		i = i + ft_putchar('%');
	else if (str[1] == 'p')
		i = i + ft_pointer(va_arg(args, void *));
	else
		return (0);
	return (i);
}

int	ft_printf(const char* str, ...)
{
	va_list args;
	int		i;
	int		length;
	int 	wrote;

	i = 0;
	wrote = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length = check_after(&str[i], args);
			wrote = wrote + length;
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			wrote++;
		}
		i++;
	}
	va_end(args);
	return (wrote);
}

#include <stdio.h> 	

int	main()
{
	int	*p;
	int	 i;

	i = 5;
	p = &i;
	printf("%d", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
    printf("\n");
    printf("%d", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
}
