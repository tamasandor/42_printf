/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:57:33 by atamas            #+#    #+#             */
/*   Updated: 2023/12/05 17:36:38 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	how_much(unsigned int number)
{
	int	such_much;

	such_much = 0;
	while (number > 9)
	{
		number /= 10;
		such_much++;
	}
	if (number >= 0)
		such_much++;
	return (such_much);
}

char	*utoa(unsigned int number)
{
	int		size;
	char	*memory;

	size = how_much(number);
	memory = ft_calloc(size + 1, sizeof(char));
	if (!memory)
		return (0);
	while (size > 0)
	{
		memory[size - 1] = (number % 10) + '0';
		number /= 10;
		size--;
	}
	return (memory);
}

/* #include <stdio.h>

int	main(void)
{
	char *ptr;

	ptr = utoa(783658764);
	printf("%s", ptr);
	free(ptr);
} */
