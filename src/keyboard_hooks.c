/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:32:33 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/14 14:07:06 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_colors(int key, t_mlx *mlx)
{
	if (key == K_1)
		mlx->f->color_scheme = 1;
	if (key == K_2)
		mlx->f->color_scheme = 2;
	if (key == K_3)
		mlx->f->color_scheme = 3;
	if (key == K_4)
		mlx->f->color_scheme = 4;
	if (key == K_5)
		mlx->f->color_scheme = 5;
	draw_fractal(mlx);
}

void	movements(int key, t_mlx *mlx)
{
	if (key == K_UP)
		mlx->center_y -= 0.1 * mlx->zoom;
	if (key == K_DOWN)
		mlx->center_y += 0.1 * mlx->zoom;
	if (key == K_LEFT)
		mlx->center_x -= 0.1 * mlx->zoom;
	if (key == K_RIGHT)
		mlx->center_x += 0.1 * mlx->zoom;
	draw_fractal(mlx);
}

void	zoom(int key, t_mlx *mlx)
{
	if (key == K_PLUS)
		mlx->zoom *= 0.9;
	if (key == K_MINUS)
		mlx->zoom *= 1.1;
	draw_fractal(mlx);
}

void	set_default_params(t_mlx *mlx)
{
	if (mlx->f->type == 1)
	{
		mlx->center_x = -1.479;
		mlx->center_y = 0;
		mlx->zoom = 0.01;
	}
	if (mlx->f->type == 2)
	{
		mlx->center_x = 0;
		mlx->center_y = 0;
		mlx->zoom = 1.5;
	}
	if (mlx->f->type == 3)
	{
		mlx->center_x = -1.755;
		mlx->center_y = -0.03;
		mlx->zoom = 0.05;
	}
	draw_fractal(mlx);
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == K_ESC)
	{
		mlx_destroy_image(mlx->ptr, mlx->img->img_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	if (key == K_SPACE)
	{
		if (mlx->f->color_scheme == 5)
			mlx->f->color_scheme = 1;
		else
			mlx->f->color_scheme += 1;
		draw_fractal(mlx);
	}
	if (key >= K_LEFT && key <= K_UP)
		movements(key, mlx);
	if (key >= K_1 && key <= K_5)
		shift_colors(key, mlx);
	if (key == K_PLUS || key == K_MINUS)
		zoom(key, mlx);
	if (key == K_DELETE)
		set_default_params(mlx);
	return (0);
}
