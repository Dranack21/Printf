/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:38:43 by habouda           #+#    #+#             */
/*   Updated: 2024/06/04 13:54:53 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_after(const char *str, va_list args)
{
	if (str[1]== 'c')
		ft_putchar(va_arg(args, int));
	/*if (str[1] == 'x')
		ft_hexa_lower(va_arg(args, int));*/
	if (str[1] == 'X')
		ft_hexa_upper(va_arg(args, int));
	if (str[1] == 'd' || str[0] == 'i' || str[0] == 'u')
		ft_putnbr(va_arg(args, int));
	if (str[1] == 's')
		ft_putstr(va_arg(args, char *));
	if (str[1] == '%')
		ft_putchar('%');
}

int	ft_printf(const char* str, ...)
{
	va_list args;
	int		i;

	i = 0;
	va_start(args, str);
	ft_putchar(str[i]);
	while (str[i])
	{
		i++;
		if (str[i] == '%')
		{
			check_after(&str[i], args);
			i = i + 2;
		}
		ft_putchar(str[i]);
	}
	va_end(args);
	return (1);
}

int	main()
{
	ft_printf("Test %X", 123);
}