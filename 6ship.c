/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6ship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:02:44 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/12 13:39:37 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	render_ship(int x, int y, t_connection *ins, t_complex z)
{
	int			i;
	double		abs_r;
	double		abs_i;
	t_complex	c;

	c.r = map_linear(x, WIDTH, ins->fractol.min_x, ins->fractol.max_x)
		+ ins->fractol.shift_x;
	c.i = map_linear(y, HEIGHT, ins->fractol.max_y, ins->fractol.min_y)
		+ ins->fractol.shift_y;
	i = 0;
	while (i < ins->fractol.iterations && z.r * z.r + z.i * z.i <= 4)
	{
		abs_r = fabs(z.r);
		abs_i = fabs(z.i);
		z.r = abs_r * abs_r - abs_i * abs_i;
		z.i = 2 * abs_r * abs_i;
		z.r += c.r;
		z.i += c.i;
		i++;
	}
	if (i < ins->fractol.iterations)
		put_pixel(&ins->image, x, y, smooth_color(i, ins));
	else
		put_pixel(&ins->image, x, y, BLACK);
}

void	ship(t_connection *ins)
{
	t_complex	z;
	int			x;
	int			y;

	z.r = 0;
	z.i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			render_ship(x, y, ins, z);
		}
	}
	mlx_put_image_to_window(ins->api, ins->win, ins->image.img, 0, 0);
}
