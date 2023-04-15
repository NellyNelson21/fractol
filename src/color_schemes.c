/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:10:25 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/14 18:06:09 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long int	color_scheme_1(int it)
{
	long int	colors[15];

	colors[0] = 0xF3A72C;
	colors[1] = 0xEB962C;
	colors[2] = 0xE28429;
	colors[3] = 0xD76E2A;
	colors[4] = 0xCC5A26;
	colors[5] = 0xC44524;
	colors[6] = 0xB93121;
	colors[7] = 0xAB2125;
	colors[8] = 0x402A5C;
	colors[9] = 0x85253A;
	colors[10] = 0x742743;
	colors[11] = 0x62294B;
	colors[12] = 0x502A55;
	colors[13] = 0x992430;
	colors[14] = 0x2E2B65;
	return (colors[it % 15]);
}

long int	color_scheme_2(int it)
{
	long int	colors[7];

	colors[0] = 0x005EAB;
	colors[1] = 0x00C1C4;
	colors[2] = 0x00C5D8;
	colors[3] = 0x00C1E3;
	colors[4] = 0x00ADE3;
	colors[5] = 0x009DDD;
	colors[6] = 0x0077C1;
	return (colors[it % 7]);
}

long int	color_scheme_3(int it)
{
	long int	colors[4];

	colors[0] = 0x232240;
	colors[1] = 0x3A395C;
	colors[2] = 0x535378;
	colors[3] = 0x8788AA;
	return (colors[it % 4]);
}

long int	color_scheme_4(int it)
{
	long int	colors[5];

	colors[4] = 0x595334;
	colors[3] = 0xD2D918;
	colors[2] = 0xBFB524;
	colors[1] = 0x8C8632;
	colors[0] = 0x595334;
	return (colors[it % 5]);
}

long int	color_scheme_5(int it)
{
	long int	colors[5];

	colors[0] = 0xF20530;
	colors[1] = 0xF205E2;
	colors[2] = 0x3F04BF;
	colors[3] = 0x05F240;
	colors[4] = 0xF2CB05;
	return (colors[it % 5]);
}
