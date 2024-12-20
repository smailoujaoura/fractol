/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3render.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:07:55 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/13 12:54:49 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	render_julia(int x, int y, t_connection *ins)
{
	t_complex	c;
	t_complex	z;
	int			i;
	double		temp;

	c.r = ins->fractol.julia_x;
	c.i = ins->fractol.julia_y;
	z.r = (ins->fractol.max_x - ins->fractol.min_x) / WIDTH * x
		+ ins->fractol.min_x + ins->fractol.shift_x;
	z.i = (ins->fractol.max_y - ins->fractol.min_y) / HEIGHT * y
		+ ins->fractol.min_y + ins->fractol.shift_y;
	i = 0;
	while (i++ < ins->fractol.iterations && z.r * z.r + z.i + z.i <= 4)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
	}
	if (i < ins->fractol.iterations)
		put_pixel(&ins->image, x, y, smooth_color(i, ins));
	else
		put_pixel(&ins->image, x, y, BLACK);
}

static void	render_mandelbrot(int x, int y, t_connection *ins)
{
	t_complex	c;
	t_complex	z;
	double		temp;
	int			i;

	z.r = 0.0;
	z.i = 0.0;
	c.r = (ins->fractol.max_x - ins->fractol.min_x) / WIDTH * x
		+ ins->fractol.min_x + ins->fractol.shift_x;
	c.i = (ins->fractol.max_y - ins->fractol.min_y) / HEIGHT * y
		+ ins->fractol.min_y + ins->fractol.shift_y;
	i = 0;
	while (i++ < ins->fractol.iterations && z.r * z.r + z.i * z.i <= 4)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
	}
	if (i < ins->fractol.iterations)
		put_pixel(&ins->image, x, y, smooth_color(i, ins));
	else
		put_pixel(&ins->image, x, y, BLACK);
}

static void	mandelbrot(t_connection *ins)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			render_mandelbrot(x, y, ins);
		}
	}
	mlx_put_image_to_window(ins->api, ins->win, ins->image.img, 0, 0);
}

static void	julia(t_connection *ins)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			render_julia(x, y, ins);
		}
	}
	mlx_put_image_to_window(ins->api, ins->win, ins->image.img, 0, 0);
}

void	render_fractol(t_connection *ins)
{
	if (ins->fractol.set == 1)
		mandelbrot(ins);
	if (ins->fractol.set == 2)
		julia(ins);
	if (ins->fractol.set == 3)
		ship(ins);
	handle_events(ins);
}
