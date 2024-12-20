/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:36:19 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/12 13:52:07 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *ptr)
{
	int				i;
	int				digit;
	unsigned long	z;
	char			hex_digits[16];

	z = (unsigned long)ptr;
	if (z == 0)
	{
		ft_putstr_fd("0x0", 1);
		return ;
	}
	else
		ft_putstr_fd("0x", 1);
	i = 0;
	while (z != 0)
	{
		digit = z & 0x0F;
		hex_digits[i] = "0123456789abcdef"[digit];
		z >>= 4;
		i++;
	}
	while (i > 0)
		ft_putchar_fd(hex_digits[--i], 1);
}

void	write_hex(unsigned int ui, char cases)
{
	char	*hex;

	if (cases == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (ui >= 16)
		write_hex(ui / 16, cases);
	ft_putchar_fd(hex[ui % 16], 1);
}
