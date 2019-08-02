/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:27:07 by moguy             #+#    #+#             */
/*   Updated: 2019/05/21 19:23:42 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int			deal_mouse2(void *mlx)
{
	double	tmp;

	if (((t_mlx*)mlx)->zoom < 0.1)
		return (0);
	tmp = ((t_mlx*)mlx)->zoom;
	((t_mlx*)mlx)->zoom /= 1.2;
	((t_mlx*)mlx)->x1 += (((double)((t_mlx*)mlx)->xmouse / tmp)
		- ((double)((t_mlx*)mlx)->xmouse / ((t_mlx*)mlx)->zoom));
	((t_mlx*)mlx)->y1 += (((double)((t_mlx*)mlx)->ymouse / tmp)
		- ((double)((t_mlx*)mlx)->ymouse / ((t_mlx*)mlx)->zoom));
	if ((((t_mlx*)mlx)->mode == 1 && ((t_mlx*)mlx)->itermax > 15)
			|| (((t_mlx*)mlx)->mode == 2 && ((t_mlx*)mlx)->itermax > 35)
			|| (((t_mlx*)mlx)->mode == 3 && ((t_mlx*)mlx)->itermax > 100))
		((t_mlx*)mlx)->itermax -= (((t_mlx*)mlx)->mode == 1) ? 0.5 : 4;
	threader(mlx);
	return (0);
}

int			deal_mouse(void *mlx)
{
	double	tmp;

	if (((t_mlx*)mlx)->zoom > (5000000000 * 1000000000))
		return (0);
	tmp = ((t_mlx*)mlx)->zoom;
	((t_mlx*)mlx)->zoom *= 1.2;
	((t_mlx*)mlx)->x1 += (((double)((t_mlx*)mlx)->xmouse / tmp)
		- ((double)((t_mlx*)mlx)->xmouse / ((t_mlx*)mlx)->zoom));
	((t_mlx*)mlx)->y1 += (((double)((t_mlx*)mlx)->ymouse / tmp)
		- ((double)((t_mlx*)mlx)->ymouse / ((t_mlx*)mlx)->zoom));
	((t_mlx*)mlx)->itermax += (((t_mlx*)mlx)->mode == 1) ? 0.5 : 4;
	threader(mlx);
	return (0);
}

int			deal_move(void *mlx)
{
	if (((t_mlx*)mlx)->onoff == 0)
	{
		((t_mlx*)mlx)->cr = (double)(((t_mlx*)mlx)->xmove - 1280) / 1280;
		((t_mlx*)mlx)->ci = (double)(((t_mlx*)mlx)->ymove - 360) / 720;
		threader(mlx);
	}
	return (0);
}

static int	deal2(int key, void *mlx)
{
	if (key == 11 && ((t_mlx*)mlx)->itermax > 0)
		((t_mlx*)mlx)->itermax -= 5;
	if (key == 45 && (((t_mlx*)mlx)->itermax < 2500 || ((t_mlx*)mlx)->nlt == 1))
		((t_mlx*)mlx)->itermax += 5;
	if (key == 69 && (((t_mlx*)mlx)->itermax < 2500 || ((t_mlx*)mlx)->nlt == 1))
		((t_mlx*)mlx)->itermax += 20;
	if (key == 78 && ((t_mlx*)mlx)->itermax > 0)
		((t_mlx*)mlx)->itermax -= 20;
	if (key == 43 && ((t_mlx*)mlx)->itermax > 0)
		((t_mlx*)mlx)->itermax -= 100;
	if (key == 47 && (((t_mlx*)mlx)->itermax < 2500 || ((t_mlx*)mlx)->nlt == 1))
		((t_mlx*)mlx)->itermax += 100;
	if (key == 67 && (((t_mlx*)mlx)->itermax < 2500 || ((t_mlx*)mlx)->nlt == 1))
		((t_mlx*)mlx)->itermax += 1000;
	if (key == 75 && ((t_mlx*)mlx)->itermax > 0)
		((t_mlx*)mlx)->itermax -= 1000;
	return (((t_mlx*)mlx)->itermax);
}

int			deal_key(int key, void *mlx)
{
	((t_mlx*)mlx)->itertest = ((t_mlx*)mlx)->itermax;
	if (key == 1 || key == 11 || key == 45 || key == 69 || key == 78
			|| key == 47 || key == 43 || key == 67 || key == 75)
		if (deal2(key, mlx) == ((t_mlx*)mlx)->itertest)
			return (0);
	if (key == 8)
		deal_color(mlx);
	if (key == 31 && ((t_mlx*)mlx)->mode == 3)
		((t_mlx*)mlx)->onoff = (((t_mlx*)mlx)->onoff == 1) ? 0 : 1;
	if (key == 48)
		init_fract(mlx);
	if (key > 122 && key < 127)
		deal_arrow(mlx, key);
	if (key == 53)
		deal_exit(mlx);
	threader(mlx);
	return (0);
}
