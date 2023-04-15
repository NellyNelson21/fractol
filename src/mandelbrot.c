/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:46:27 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/12 18:57:10 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot_plenty(t_mlx *mlx)
{
	int		i;
	double	tempx;

	i = 0;
	while ((mlx->f->z_x * mlx->f->z_x + mlx->f->z_y * mlx->f->z_y <= 4)
		&& (i < mlx->iteration_limit))
	{
		tempx = mlx->f->z_x * mlx->f->z_x
			- mlx->f->z_y * mlx->f->z_y + mlx->f->const_x;
		mlx->f->z_y = 2 * mlx->f->z_x * mlx->f->z_y + mlx->f->const_y;
		mlx->f->z_x = tempx;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	int		iterations;
	int		x;
	int		y;

	x = 0;
	mlx->scale = WIN_SIZE / 2 / mlx->zoom;
	while (x < WIN_SIZE)
	{
		y = 0;
		while (y < WIN_SIZE)
		{
			mlx->f->const_x = (x - WIN_SIZE / 2) / mlx->scale + mlx->center_x;
			mlx->f->const_y = (y - WIN_SIZE / 2) / mlx->scale + mlx->center_y;
			mlx->f->z_x = 0;
			mlx->f->z_y = 0;
			iterations = calculate_mandelbrot_plenty(mlx);
			if (iterations == mlx->iteration_limit)
				my_mlx_pixel_put(mlx->img, x, y, 0x000000);
			else
				my_mlx_pixel_put(mlx->img, x, y, get_color(iterations, mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->img_ptr, 0, 0);
}
