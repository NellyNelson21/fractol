/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:04:09 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/14 17:17:17 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_esc(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img->img_ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}

int	mouse_zoom(int key, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (key == MOUSE_UP)
		mlx->zoom *= 0.9;
	if (key == MOUSE_DOWN)
		mlx->zoom *= 1.1;
	draw_fractal(mlx);
	return (0);
}
