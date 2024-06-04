/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:38:43 by habouda           #+#    #+#             */
/*   Updated: 2024/06/05 00:46:34 by habouda          ###   ########.fr       */
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
	if (str[1] && (str[1] == 'x'))
		i = i + ft_hexa_lower(va_arg(args, int));
	if (str[1] && (str[1] == 'X'))
		i = i + ft_hexa_upper(va_arg(args, int));
	if ((str[1] && str[1] == 'd') || str[1] == 'i' || str[1] == 'u')
		i = i + ft_putnbr(va_arg(args, int));
	if (str[1] && str[1] == 's')
		i = i + ft_putstr(va_arg(args, char *));
	if (str[1] && str[1] == '%')
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


int main() {
    int number = 6719;

    // Using the standard printf
    printf("Standard printf with %%x: %x\n", number);

    // Using the custom ft_printf
    ft_printf("Custom ft_printf with %%x: %x\n", number);

    // Testing with another value
    number = 65518;
    printf("Standard printf with %%x: %x\n", number);
    ft_printf("Custom ft_printf with %%x: %x\n", number);

    return 0;
}
