/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:27:04 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/16 10:08:49 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	loop_over_specifiers(va_list args, char format_specifier, int *flag)
{
	if (format_specifier == 'c')
		print_char(va_arg(args, int));
	else if (format_specifier == 's')
		print_string(va_arg(args, char *));
	else if (format_specifier == 'i' || format_specifier == 'd')
		print_integer(va_arg(args, int), flag);
	else if (format_specifier == 'p')
		print_pointer(va_arg(args, void *));
	else if (format_specifier == 'u')
		print_unsinged(va_arg(args, unsigned int));
	else if (format_specifier == 'x' || format_specifier == 'X')
		print_hex(va_arg(args, unsigned int), format_specifier, flag);
	else if (format_specifier == '%')
		print_char('%');
}

static char	is_specifier(char c)
{
	char	*format_specifiers;
	int		i;

	i = 0;
	format_specifiers = "cspdiuxX%";
	while (format_specifiers[i])
	{
		if (c == format_specifiers[i])
			return (format_specifiers[i]);
		i++;
	}
	return (0);
}

static int	get_specifier(const char *str, int *i, char sp, int *flag)
{
	(*i)++;
	while (str[*i] == ' ' || str[*i] == '+' || str[*i] == '#')
	{
		if (str[*i] == '+')
			flag[0] = 1;
		if (str[*i] == ' ')
			flag[1] = 1;
		if (str[*i] == '#')
			flag[2] = 1;
		(*i)++;
	}
	sp = is_specifier(str[*i]);
	return (sp);
}

static void	parse_formated_string(const char *str, va_list args)
{
	char	specifier;
	int		flag[3];
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			specifier = 0;
			flag[0] = 0;
			flag[1] = 0;
			flag[2] = 0;
			specifier = get_specifier((char *)str, &i, specifier, flag);
			if (specifier)
			{
				loop_over_specifiers(args, specifier, flag);
				i++;
			}
		}
		else
			ft_putchar_fd(str[i++], 1);
	}
}

int	ft_printf(const char *formated_string, ...)
{
	va_list	args;

	if (write(1, NULL, 0) == -1)
		return (-1);
	count_printed_chars(-1);
	va_start(args, formated_string);
	parse_formated_string(formated_string, args);
	va_end(args);
	return (count_printed_chars(0));
}
