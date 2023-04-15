/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:51:45 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/11 17:10:05 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, long int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_mlx *mlx)
{
	if (mlx->f->type == 1)
		draw_mandelbrot(mlx);
	else if (mlx->f->type == 2)
		draw_julia(mlx);
	else if (mlx->f->type == 3)
		draw_burningship(mlx);
}
