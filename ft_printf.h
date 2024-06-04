#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_pointer(void *ptr);
void	ft_hexa_upper(int n);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_hexa_lower(int n);

int		ft_printf(const char* str, ...);

size_t	ft_strlen(const char *s);

#endif