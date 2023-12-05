/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:50 by atamas            #+#    #+#             */
/*   Updated: 2023/12/04 18:18:30 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	print_str(char *c)
{
	int	len;

	len = 0;
	while (c[len])
	{
		write(1, &c[len], 1);
		len++;
	}
	return (len);
}

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	handler(char font, va_list args)
{
	int i;

	i = 0;
	if (font == 'c')
	{
		i += print_char(va_arg(args, int));
	}
	if (font == 's')
	{
		i += print_str(va_arg(args, char *));
	}
/* 	if (font == 'p')
	{
		i += print_str(pointer_address)
	} */
	return (i);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			len += handler(*string, args);
		}
		else
		{
			len += write(1, string, 1);
		}
		string++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int	length = ft_printf("Alma %s, %c", "Please work", 'c');
	printf("\n%d\n", length);
}
/* 
cspdiuxX%
 */

/* 
•%c Prints a single character.
•%s Prints a string (as defined by the common C convention).
•%p The void * pointer argument has to be printed in hexadecimal format.
•%d Prints a decimal (base 10) number.
•%i Prints an integer in base 10.
•%u Prints an unsigned decimal (base 10) number.
•%x Prints a number in hexadecimal (base 16) lowercase format.
•%X Prints a number in hexadecimal (base 16) uppercase format.
•%% Prints a percent sign.
 */