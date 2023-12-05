/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:00:52 by atamas            #+#    #+#             */
/*   Updated: 2023/12/05 14:13:47 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_str(char *c)
{
	int	len;

	len = 0;
	if (!c)
		return (-1);
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
