/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:30:40 by clima-fr          #+#    #+#             */
/*   Updated: 2023/06/06 16:16:57 by clima-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	putstr(char *str, int *size)
{
	if (!str)
	str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		*size = *size + 1;
		str++;
	}
}

void	putnbr(long long int nbr, int base, int *size)
{
	char	*digits = "0123456789abcdef";

	if (nbr < 0)
	{
		*size = *size + 1;
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > base)
		putnbr(nbr / base, base, size);
	write (1, &digits[nbr % base], 1);
	*size = *size + 1;
}

int	ft_printf(const char *format, ...)
{
	int	size = 0;
	va_list	pointer;

	va_start (pointer, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd' || *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				putstr (va_arg(pointer, char *), &size);
			else if (*format == 'd')
				putnbr ((long long int)va_arg(pointer, int), 10, &size);
			else if (*format == 'x')
				putnbr ((long long int)va_arg(pointer, unsigned int), 16, &size);
		}
		else
		{
			write (1, format, 1);
			size++;
		}
		format++;
	}
	va_end(pointer);
	return (size);
}
/*#include <stdio.h>
int main()
{ 
    int return1 = ft_printf("Meu nome eh %s e eu tenho %d anos\n", "Clara", 23);
    int return2 = ft_printf("Testando o numero %d em hexadecimal: %x\n", 42, 42);
    printf("%d\n", return1);
    printf("%d\n", return2);
    return1 = printf("Meu nome eh %s e eu tenho %d anos\n", "Clara", 23);
    return2 = printf("Testando o numero %d em hexadecimal: %x\n", 42, 42);
    printf("%d\n", return1);
    printf("%d\n", return2);
}*/
