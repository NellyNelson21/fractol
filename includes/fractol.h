/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreys <andreys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:52:24 by nnelson           #+#    #+#             */
/*   Updated: 2023/04/15 15:18:20 by andreys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"

# include "keys.h"

# define WIN_SIZE 700

typedef struct s_fractal
{
	double	const_x;
	double	const_y;
	double	z_x;
	double	z_y;
	int		type;
	int		color_scheme;
}	t_fractal;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	int			iteration_limit;
	double		scale;
	double		center_x;
	double		center_y;
	double		zoom;
	t_img		*img;
	t_fractal	*f;
}	t_mlx;

//init_fractal
int			validate_fractal(int argc, char **argv, t_mlx *mlx);

//libft_utils
int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(const char *str);
double		ft_atod(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *str);

//drawing functions
void		draw_mandelbrot(t_mlx *mlx);
void		draw_julia(t_mlx *mlx);
void		draw_burningship(t_mlx *mlx);
void		draw_fractal(t_mlx *mlx);
void		my_mlx_pixel_put(t_img *img, int x, int y, long int color);

//colors
long int	get_color(int iterations, t_mlx *mlx);
long int	color_scheme_1(int it);
long int	color_scheme_2(int it);
long int	color_scheme_3(int it);
long int	color_scheme_4(int it);
long int	color_scheme_5(int it);

//hooks
int			mouse_zoom(int key, int x, int y, t_mlx *mlx);
int			mouse_esc(t_mlx *mlx);
int			key_hook(int key, t_mlx *mlx);

#endif