/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4events.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:08:35 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/16 13:06:25 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	destroy(t_connection *ins)
{
	exit_cleanly(ins);
	exit(0);
}

static void	update_scale(t_connection *ins, double zoom_factor,
double mouse_x, double mouse_y)
{
	double	range_x;
	double	range_y;
	double	new_x;
	double	new_y;

	range_x = ins->fractol.max_x - ins->fractol.min_x;
	range_y = ins->fractol.max_y - ins->fractol.min_y;
	new_x = range_x * zoom_factor;
	new_y = range_y * zoom_factor;
	ins->fractol.min_x = mouse_x - new_x * ((double)ins->pointer_x / WIDTH);
	ins->fractol.min_y = mouse_y - new_y * ((double)ins->pointer_y / HEIGHT);
	ins->fractol.max_x = ins->fractol.min_x + new_x;
	ins->fractol.max_y = ins->fractol.min_y + new_y;
}

static int	handle_mouse(int button, int x, int y, t_connection *ins)
{
	double	mouse_x;
	double	mouse_y;

	(void)x;
	(void)y;
	mlx_mouse_get_pos(ins->win, &ins->pointer_x, &ins->pointer_y);
	if (ins->fractol.set == 3)
		ins->pointer_y = HEIGHT - ins->pointer_y;
	mouse_x = map_linear(ins->pointer_x,
			WIDTH, ins->fractol.min_x, ins->fractol.max_x);
	mouse_y = map_linear(ins->pointer_y,
			HEIGHT, ins->fractol.min_y, ins->fractol.max_y);
	if (button == 4)
	{
		update_scale(ins, 0.8, mouse_x, mouse_y);
		ins->fractol.zoom *= 0.8;
	}
	else if (button == 5)
	{
		update_scale(ins, 1.2, mouse_x, mouse_y);
		ins->fractol.zoom *= 1.2;
	}
	render_fractol(ins);
	return (0);
}

static int	handle_keys(int keysym, t_connection *ins)
{
	if (keysym == KEY_ESCAPE)
		exit_cleanly(ins);
	else if (keysym == KEY_SPACE)
		change_color(ins);
	else if (keysym == KEY_R)
		return (reset_view(ins), render_fractol(ins), 0);
	else if (keysym == KEY_RIGHT)
		ins->fractol.shift_x += (0.5 * ins->fractol.zoom);
	else if (keysym == KEY_LEFT)
		ins->fractol.shift_x -= (0.5 * ins->fractol.zoom);
	else if (keysym == KEY_UP && ins->fractol.set == 3)
		ins->fractol.shift_y -= (0.5 * ins->fractol.zoom);
	else if (keysym == KEY_DOWN && ins->fractol.set == 3)
		ins->fractol.shift_y += (0.5 * ins->fractol.zoom);
	else if (keysym == KEY_UP)
		ins->fractol.shift_y += (0.5 * ins->fractol.zoom);
	else if (keysym == KEY_DOWN)
		ins->fractol.shift_y -= (0.5 * ins->fractol.zoom);
	else if (keysym == KEY_PLUS)
		ins->fractol.iterations += 25;
	else if (keysym == KEY_MINUS)
		ins->fractol.iterations -= 25;
	return (render_fractol(ins), 0);
}

void	handle_events(t_connection *ins)
{
	mlx_mouse_hook(ins->win, handle_mouse, ins);
	mlx_key_hook(ins->win, handle_keys, ins);
	mlx_hook(ins->win, 17, 0, destroy, ins);
	mlx_loop(ins->api);
}
