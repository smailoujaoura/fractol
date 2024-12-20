/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necessary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:25:59 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/06 21:41:49 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *str)
{
	ft_putstr_fd(str, 1);
}

void	print_integer(int i, int *flag)
{
	if (i >= 0)
	{
		if (flag[0])
			ft_putchar_fd('+', 1);
		else if (flag[1])
			ft_putchar_fd(' ', 1);
	}
	ft_putnbr_fd(i, 1);
}

void	print_char(char c)
{
	ft_putchar_fd(c, 1);
}

void	print_hex(unsigned int i, char cases, int *flag)
{
	if (flag[2] && i != 0)
	{
		if (cases == 'X')
			ft_putstr_fd("0X", 1);
		if (cases == 'x')
			ft_putstr_fd("0x", 1);
	}
	write_hex(i, cases);
}

void	print_unsinged(unsigned int ui)
{
	if (ui < 10)
		ft_putchar_fd(ui % 10 + '0', 1);
	else
	{
		print_unsinged(ui / 10);
		print_unsinged(ui % 10);
	}
}
