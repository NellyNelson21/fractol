/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:52:58 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/14 16:50:33 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot_params(int argc, char **argv, t_mlx *mlx)
{
	mlx->center_x = -1.479;
	mlx->zoom = 0.01;
	mlx->iteration_limit = 100;
	mlx->f->color_scheme = 1;
	if (argc == 3)
		mlx->iteration_limit = ft_atoi(argv[4]);
}

void	init_julia_params(int argc, char **argv, t_mlx *mlx)
{
	mlx->zoom = 1.5;
	mlx->iteration_limit = 100;
	mlx->f->color_scheme = 1;
	if (argc > 2)
	{
		if (argc >= 3)
			mlx->f->const_x = ft_atod(argv[2]);
		if (argc >= 4)
			mlx->f->const_y = ft_atod(argv[3]);
		if (argc == 5)
			mlx->iteration_limit = ft_atoi(argv[4]);
	}
}

void	init_burningship_params(int argc, char **argv, t_mlx *mlx)
{
	mlx->center_x = -1.755;
	mlx->center_y = -0.03;
	mlx->zoom = 0.05;
	mlx->iteration_limit = 35;
	mlx->f->color_scheme = 1;
	if (argc == 3)
		mlx->iteration_limit = ft_atoi(argv[4]);
}

int	check_fractal_name(int argc, char **argv, t_mlx *mlx)
{
	if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "Mandelbrot"))
	{
		mlx->f->type = 1;
		init_mandelbrot_params(argc, argv, mlx);
		return (1);
	}
	else if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "Julia"))
	{
		mlx->f->type = 2;
		init_julia_params(argc, argv, mlx);
		return (1);
	}
	else if (!ft_strcmp(argv[1], "burningship")
		|| !ft_strcmp(argv[1], "Burningship"))
	{
		mlx->f->type = 3;
		init_burningship_params(argc, argv, mlx);
		return (1);
	}
	else
		return (0);
}

int	validate_fractal(int argc, char **argv, t_mlx *mlx)
{
	if (argc < 2)
	{
		ft_putstr("ERROR: not enough arguments\n");
		ft_putstr("\n");
		ft_putstr("Programm must execute as follow:\n");
		ft_putstr("./fractol <FRACTAL NAME>\n");
		return (0);
	}
	if (!check_fractal_name(argc, argv, mlx))
	{
		ft_putstr("ERROR: INVALID FRACTAL NAME\n");
		ft_putstr("\n");
		ft_putstr("Possible fractal names:\n");
		ft_putstr("Mandelbrot, Julia or Burningship\n");
		return (0);
	}
	return (1);
}
