/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:52:57 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/10 16:08:24 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long int	get_color(int iterations, t_mlx *mlx)
{
	if (mlx->f->color_scheme == 1)
		return (color_scheme_1(iterations));
	else if (mlx->f->color_scheme == 2)
		return (color_scheme_2(iterations));
	else if (mlx->f->color_scheme == 3)
		return (color_scheme_3(iterations));
	else if (mlx->f->color_scheme == 4)
		return (color_scheme_4(iterations));
	else if (mlx->f->color_scheme == 5)
		return (color_scheme_5(iterations));
	else
		return (0);
}
