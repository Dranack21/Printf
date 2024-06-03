/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:38:43 by habouda           #+#    #+#             */
/*   Updated: 2024/06/03 16:01:54 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		while (n >= 10)
		{
			ft_putnbr(n / 10);
			n = n % 10;
		}
		ft_putchar(n + 48);
	}
}
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	check_after(const char *str, va_list args)
{
	if (str[1]== 'c')
		ft_putchar(va_arg(args, int));
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
	int		k;

	k = 0;
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
	ft_printf("Salut je m'apelle %s j'ai %d ans et je sais pas %c", "HUGO", 20, 'A');
}