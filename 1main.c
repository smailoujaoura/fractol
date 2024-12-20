/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:00:48 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/13 14:15:33 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	initialize(t_connection *ins, char *title)
{
	ins->fractol.iterations = 70;
	ins->fractol.zoom = 1.0;
	ins->fractol.min_x = -2.0;
	ins->fractol.max_x = 2.0;
	ins->fractol.min_y = 2.0;
	ins->fractol.max_y = -2.0;
	ins->pointer_x = WIDTH / 2;
	ins->pointer_y = HEIGHT / 2;
	ins->api = mlx_init();
	if (ins->api == NULL)
		memory_error();
	ins->win = mlx_new_window(ins->api, WIDTH, HEIGHT, title);
	if (ins->win == NULL)
		memory_error();
	ins->image.img = mlx_new_image(ins->api, WIDTH, HEIGHT);
	if (ins->image.img == NULL)
		memory_error();
	ins->image.ptr = mlx_get_data_addr(ins->image.img,
			&ins->image.bpp, &ins->image.line_len, &ins->image.endian);
	ins->fractol.r = 0;
	ins->fractol.g = 0.3;
	ins->fractol.b = 0.6;
}

int	main(int argc, char *argv[])
{
	t_connection	instance;

	if (validate_usage(argc, argv, &instance.fractol) == 0)
		return (invalidate_usage());
	initialize(&instance, argv[1]);
	ft_printf("Mouse wheel for zoom.\n");
	ft_printf("R key for zoom reset.\n");
	ft_printf("Space for color change.\n");
	ft_printf("Arrow keys for moving.\n");
	ft_printf("+ & - for iterations control.\n");
	render_fractol(&instance);
}
