/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:54:36 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/14 20:55:42 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_fractal	fractal;

	mlx.img = &img;
	mlx.f = &fractal;
	if (!validate_fractal(argc, argv, &mlx))
		exit(-1);
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		exit(-1);
	mlx.win = mlx_new_window(mlx.ptr, WIN_SIZE, WIN_SIZE, argv[1]);
	if (!mlx.win)
		exit(-1);
	img.img_ptr = mlx_new_image(mlx.ptr, WIN_SIZE, WIN_SIZE);
	if (!img.img_ptr)
		exit(-1);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_fractal(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_zoom, &mlx);
	mlx_hook(mlx.win, 17, 0, mouse_esc, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
