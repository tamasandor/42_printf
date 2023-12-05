/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:02:16 by atamas            #+#    #+#             */
/*   Updated: 2023/12/05 18:22:40 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"

int		print_str(char *c);
int		print_char(char c);
void	ptr_address(char *ptr);
int		ft_printf(const char *string, ...);
char	*utoa(unsigned int number);

#endif