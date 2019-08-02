/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:45:17 by moguy             #+#    #+#             */
/*   Updated: 2019/04/09 08:15:33 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	fill_color0(void *mlx, int i, int *x, int *y)
{
	while (i > 9)
		i -= 10;
	if (i == 0)
		fill_pixel(mlx, 0xFF0000, x, y);
	else if (i == 1)
		fill_pixel(mlx, 0x800000, x, y);
	else if (i == 2)
		fill_pixel(mlx, 0xFF0000, x, y);
	else if (i == 3)
		fill_pixel(mlx, 0xFF8000, x, y);
	else if (i == 4)
		fill_pixel(mlx, 0xFFFF00, x, y);
	else if (i == 5)
		fill_pixel(mlx, 0xFFFF80, x, y);
	else if (i == 6)
		fill_pixel(mlx, 0xFFFFFF, x, y);
	else if (i == 7)
		fill_pixel(mlx, 0xFFFF80, x, y);
	else if (i == 8)
		fill_pixel(mlx, 0xFFFF00, x, y);
	else if (i == 9)
		fill_pixel(mlx, 0xFF8000, x, y);
}

static void	fill_color1(void *mlx, int i, int *x, int *y)
{
	int		n;
	float	j;

	n = 0;
	j = i;
	while (j > 175)
		j -= 175;
	if (j <= 25)
		n = 10158080 + j * 262144;
	else if (j > 25 && j <= 75)
		n = 16711680 + (int)((j - 25) * 5.1) * 257;
	else if (j > 75 && j <= 100)
		n = 16777215 - (int)((j - 75) * 10.2) * 65536;
	else if (j > 100 && j <= 125)
		n = 65535 - (int)((j - 100) * 7.2) * 256;
	else if (j > 125 && j <= 150)
	{
		n = 19455 - (j - 125) * 768;
		n = n - (int)((j - 125) * 10.2);
	}
	else if (j > 150 && j <= 175)
		n = (int)((j - 150) * 6.2) * 65536;
	fill_pixel(mlx, n, x, y);
}

static void	fill_color2(void *mlx, int i, int *x, int *y)
{
	int		n;
	float	j;
	float	k;

	k = i;
	j = i * 255;
	if (((t_mlx*)mlx)->colorset == 2)
		n = (int)(j / ((t_mlx*)mlx)->itermax) * 65536;
	else if (((t_mlx*)mlx)->colorset == 3)
		n = (int)(j / ((t_mlx*)mlx)->itermax) * 256;
	else if (((t_mlx*)mlx)->colorset == 4)
		n = (int)(j / ((t_mlx*)mlx)->itermax);
	else if (((t_mlx*)mlx)->colorset == 5)
		n = (int)(j / ((t_mlx*)mlx)->itermax) * 65793;
	else if (((t_mlx*)mlx)->colorset == 6)
	{
		n = 6553600 + (int)(k * 155 / ((t_mlx*)mlx)->itermax) * 65536;
		n += (int)(j / ((t_mlx*)mlx)->itermax) * 257;
	}
	else
		n = 255 + (int)(j / ((t_mlx*)mlx)->itermax) * 256;
	fill_pixel(mlx, n, x, y);
}

void		fill_color(void *mlx, int i, int *x, int *y)
{
	if (((t_mlx*)mlx)->colorset == 0)
		fill_color0(mlx, i, x, y);
	else if (((t_mlx*)mlx)->colorset == 1)
		fill_color1(mlx, i, x, y);
	else
		fill_color2(mlx, i, x, y);
}
