/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2checks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:40:00 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/15 09:05:04 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	str_to_double(char *s)
{
	double	fraction;
	double	whole;
	int		sign;
	int		pow;

	(1 && (sign = 1, pow = 10, whole = 0, fraction = 0));
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (*s && *s != '.')
		whole = whole * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s)
		{
			fraction = fraction + ((double)(*s - '0') / pow);
			1 && (pow *= 10, s++);
		}
	}
	return (((whole + fraction) * sign));
}

static int	check_numbers(char *n)
{
	int	point;

	if (*n != '+' && *n != '-' && !ft_isdigit(*n))
		return (1);
	if (*n == '+' || *n == '-')
		n++;
	if (*n == '.')
		return (1);
	point = 0;
	while (*n)
	{
		if (*n == '.')
			point++;
		if (point > 1 || (!ft_isdigit(*n) && *n != '.'))
			return (1);
		n++;
	}
	if (*--n == '.')
		return (1);
	return (0);
}

int	validate_usage(int argc, char **argv, t_fractols *fractol)
{
	if (argc == 2 && !ft_strncmp("Mandelbrot", argv[1], 11))
	{
		fractol->set = 1;
		return (1);
	}
	else if (argc == 4 && !ft_strncmp("Julia", argv[1], 6))
	{
		fractol->set = 2;
		if (check_numbers(argv[2]) || check_numbers(argv[3]))
			return (0);
		fractol->julia_x = str_to_double(argv[2]);
		fractol->julia_y = str_to_double(argv[3]);
		if (isinf(fractol->julia_x) || isinf(fractol->julia_y))
			return (0);
		return (1);
	}
	else if (argc == 2 && !ft_strncmp("Ship", argv[1], 5))
	{
		fractol->set = 3;
		return (1);
	}
	return (0);
}

int	invalidate_usage(void)
{
	ft_printf("\nUse as follows:\n\n");
	ft_printf("./fractol Julia r i\n");
	ft_printf("./fractol Mandelbrot\n");
	ft_printf("./fractol Ship\n");
	ft_printf("\nWhere r is the real component ");
	ft_printf("and i is the imaginary component:\n");
	ft_printf("./fractol Julia -0.4 0.6\n");
	ft_printf("\n");
	return (1);
}
