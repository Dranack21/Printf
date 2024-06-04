/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:38:43 by habouda           #+#    #+#             */
/*   Updated: 2024/06/04 15:22:46 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_after(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (str[1]== 'c')
	{
		ft_putchar(va_arg(args, int));
		i++;
	}
	if (str[1] == 'x')
		i = i + ft_hexa_lower(va_arg(args, int));
	if (str[1] == 'X')
		i = i + ft_hexa_upper(va_arg(args, int));
	if (str[1] == 'd' || str[0] == 'i' || str[0] == 'u')
		i = i + ft_putnbr(va_arg(args, int));
	if (str[1] == 's')
		i = i + ft_putstr(va_arg(args, char *));
	if (str[1] == '%')
	{
		i++;
		ft_putchar('%');
	}
	if (str[1] == 'p')
		ft_pointer(va_arg(args, void *));
	return (i);
}

int	ft_printf(const char* str, ...)
{
	va_list args;
	int		i;
	int		k;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			k = check_after(&str[i], args);
			i = i + 2;
		}
		ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (k);
}
#include <stdio.h>

int	main()
{
	ft_printf("%s", "abc");
}