/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5utils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:19 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/13 14:22:37 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	map_linear(double v, double max1, double min2, double max2)
{
	return ((max2 - min2) / max1 * v + min2);
}

void	memory_error(void)
{
	perror("Error: ");
	exit(1);
}

int	exit_cleanly(t_connection *ins)
{
	mlx_destroy_image(ins->api, ins->image.img);
	mlx_destroy_window(ins->api, ins->win);
	exit(0);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (x * (img->bpp / 8)) + (y * img->line_len);
	*(int *)(img->ptr + offset) = color;
}

int	smooth_color(int i, t_connection *ins)
{
	double	p;
	double	r;
	double	g;
	double	b;

	p = (double)i / ins->fractol.iterations;
	r = fabs(sin((p + ins->fractol.r) * M_PI));
	g = fabs(sin((p + ins->fractol.g) * M_PI));
	b = fabs(sin((p + ins->fractol.b) * M_PI));
	return (((int)(r * 255) << 16) | ((int)(g * 255) << 8) | (int)(b * 255));
}
