/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:38:43 by habouda           #+#    #+#             */
/*   Updated: 2024/06/03 15:00:19 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	check_after(const char *str)
{
	if (str == "c")
		ft_putchar(str[0]);
	if (str == "d" || str == "i" || str == "u")
		ft_putnbr(str);
	if (str == "s")
		ft_putstr(str);
	if (str == "%")
		ft_putchar("%");
	
}

int	ft_printf(const char* str, ...)
{
	va_list args;
	int		count;

	va_start(args, str);
	while (str && str != "%")
		str++;

	if (str == "%")
		check_after(str);
}
