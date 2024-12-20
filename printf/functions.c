/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:46:01 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/16 10:09:53 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_printed_chars(int start)
{
	static int	return_value;

	if (start == -1)
		return_value = 0;
	else if (start == 1)
		return_value++;
	return (return_value);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
	count_printed_chars(1);
}

void	ft_putnbr_fd(int i, int fd)
{
	long	num;

	num = i;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	if (num < 10)
		ft_putchar_fd(num % 10 + '0', 1);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}
