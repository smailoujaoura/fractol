/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5utils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:52:59 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/13 12:58:36 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	reset_view(t_connection *ins)
{
	ins->fractol.max_x = 2;
	ins->fractol.min_x = -2;
	ins->fractol.min_y = 2;
	ins->fractol.max_y = -2;
	ins->fractol.zoom = 1;
}

void	change_color(t_connection *ins)
{
	static int	i;

	if (i == 0)
	{
		ins->fractol.r = 0.3;
		ins->fractol.g = 0.6;
		ins->fractol.b = 0.0;
	}
	else if (i == 1)
		1 && (ins->fractol.r = 0.0, ins->fractol.g = 0.6, ins->fractol.b = 0.3);
	else if (i == 2)
		1 && (ins->fractol.r = 0.3, ins->fractol.g = 0.0, ins->fractol.b = 0.6);
	else if (i == 3)
		1 && (ins->fractol.r = 0.6, ins->fractol.g = 0.0, ins->fractol.b = 0.3);
	else if (i == 4)
		1 && (ins->fractol.r = 0.6, ins->fractol.g = 0.3, ins->fractol.b = 0.0);
	else if (i == 5)
		1 && (ins->fractol.r = 0.3, ins->fractol.g = 0.6, ins->fractol.b = 0.0);
	else if (i == 6)
		i = 0;
	i++;
}
