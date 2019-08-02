/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:47:44 by moguy             #+#    #+#             */
/*   Updated: 2019/07/13 03:23:09 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	draw2(void *mlx, int *x, int *y, int i)
{
	if (i < ((t_mlx*)mlx)->itermax)
		fill_color(mlx, i, x, y);
	else
		fill_pixel(mlx, 0x0, x, y);
}

static void	draw_julia(void *mlx, int *x, int *y)
{
	double	zr[2];
	double	zi[3];
	int		i;

	zr[0] = (double)*x / ((t_mlx*)mlx)->zoom + ((t_mlx*)mlx)->x1;
	zi[0] = (double)*y / ((t_mlx*)mlx)->zoom + ((t_mlx*)mlx)->y1;
	zr[1] = zr[0] * zr[0];
	zi[1] = zi[0] * zi[0];
	zi[2] = zi[0] * zr[0];
	i = 0;
	while ((zr[1] + zi[1]) < 4 && i <= ((t_mlx*)mlx)->itermax)
	{
		zr[0] = zr[1] - zi[1] + ((t_mlx*)mlx)->cr;
		zi[0] = zi[2] + zi[2] + ((t_mlx*)mlx)->ci;
		zr[1] = zr[0] * zr[0];
		zi[1] = zi[0] * zi[0];
		zi[2] = zi[0] * zr[0];
		i++;
	}
	draw2(mlx, x, y, i);
}

static void	draw_burn(void *mlx, int *x, int *y)
{
	double	cr;
	double	ci;
	double	zr[2];
	double	zi[3];
	int		i;

	cr = (double)*x / ((t_mlx*)mlx)->zoom + ((t_mlx*)mlx)->x1;
	ci = (double)*y / ((t_mlx*)mlx)->zoom + ((t_mlx*)mlx)->y1;
	zr[0] = 0;
	zi[0] = 0;
	zr[1] = 0;
	zi[1] = 0;
	zi[2] = 0;
	i = 0;
	while ((zr[1] + zi[1]) < 4 && i < ((t_mlx*)mlx)->itermax)
	{
		zr[0] = zr[1] - zi[1] + cr;
		zi[0] = fabsl(zi[2]) + fabsl(zi[2]) + ci;
		zr[1] = zr[0] * zr[0];
		zi[1] = zi[0] * zi[0];
		zi[2] = zi[0] * zr[0];
		i++;
	}
	draw2(mlx, x, y, i);
}

static void	draw_mandel(void *mlx, int *x, int *y)
{
	double	cr;
	double	ci;
	double	zr[2];
	double	zi[3];
	int		i;

	cr = (double)*x / ((t_mlx*)mlx)->zoom + ((t_mlx*)mlx)->x1;
	ci = (double)*y / ((t_mlx*)mlx)->zoom + ((t_mlx*)mlx)->y1;
	zr[0] = 0;
	zi[0] = 0;
	zr[1] = 0;
	zi[1] = 0;
	zi[2] = 0;
	i = -1;
	while ((zr[1] + zi[1]) < 4 && ++i < ((t_mlx*)mlx)->itermax)
	{
		zr[0] = zr[1] - zi[1] + cr;
		zi[0] = zi[2] + zi[2] + ci;
		zr[1] = zr[0] * zr[0];
		zi[1] = zi[0] * zi[0];
		zi[2] = zi[0] * zr[0];
	}
	draw2(mlx, x, y, i);
}

void		fract_ol(void *mlx)
{
	int		xstart;
	int		ttot;
	int		x;
	int		y;

	y = 0;
	ttot = ((t_mlx*)mlx)->width / 4;
	xstart = ttot * get_thread(pthread_self(), mlx);
	while (y < ((t_mlx*)mlx)->heigth)
	{
		x = xstart;
		while (x < ((t_mlx*)mlx)->width && x < (xstart + ttot))
		{
			if (((t_mlx*)mlx)->mode == 3)
				draw_julia(mlx, &x, &y);
			else if (((t_mlx*)mlx)->mode == 2)
				draw_mandel(mlx, &x, &y);
			else
				draw_burn(mlx, &x, &y);
			x++;
		}
		y++;
	}
}
