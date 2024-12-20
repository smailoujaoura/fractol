/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:18:44 by soujaour          #+#    #+#             */
/*   Updated: 2024/12/16 13:10:56 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define BLUE 0x00008B

# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_ESCAPE 53
# define KEY_SPACE 49
# define KEY_R 15

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractols
{
	int		set;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		iterations;

	double	julia_x;
	double	julia_y;

	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;

	double	r;
	double	g;
	double	b;

	int		color;
}	t_fractols;

typedef struct s_image
{
	void	*img;
	char	*ptr;
	int		bpp;
	int		line_len;
	int		endian;

	double	zoom_level;
}	t_image;

typedef struct s_connection
{
	void		*api;
	void		*win;

	int			pointer_x;
	int			pointer_y;
	t_image		image;
	t_fractols	fractol;
	double		scale_x;
	double		sclae_y;
}	t_connection;

int		validate_usage(int argc, char **argv, t_fractols *fractol);
int		invalidate_usage(void);
void	render_fractol(t_connection *ins);
void	handle_events(t_connection *ins);
double	map_linear(double v, double max1, double min2, double max2);
void	memory_error(void);
int		exit_cleanly(t_connection *ins);
void	put_pixel(t_image *img, int x, int y, int color);
int		smooth_color(int i, t_connection *ins);
void	ship(t_connection *ins);
void	change_color(t_connection *ins);
void	reset_view(t_connection *ins);

#endif