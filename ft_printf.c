/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:50 by atamas            #+#    #+#             */
/*   Updated: 2023/12/05 18:23:25 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	handler(char font, va_list args)
{
	int		i;
	char	*ptr;

	i = 0;
	if (font == 'c')
		i += print_char(va_arg(args, int));
	if (font == 's')
		i += print_str(va_arg(args, char *));
	if (font == '%')
		i += print_char('%');
	if (font == 'd' || font == 'i')
	{
		ptr = ft_itoa(va_arg(args, int));
		i += print_str(ptr);
		free(ptr);
	}
	if (font == 'u')
	{
		ptr = utoa(va_arg(args, unsigned int));
		i += print_str(ptr);
		free(ptr);
	}
/* 	if (font == 'p')
	{
		ptr = va_arg(args, char *);
		char *address;
		address = ptr;
		i += print_str(address);
	} */
	return (i);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;
	int		temp;

	len = 0;
	temp = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			temp = handler(*string, args);
			if (temp < 0)
				len += print_str("(null)");
			else
				len += temp;
		}
		else
			len += write(1, string, 1);
		string++;
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	int	length = ft_printf("Alma %s, %c", "Please work", 'c');
	printf("\n%d\n", length);
} */
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