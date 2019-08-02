/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:05:46 by moguy             #+#    #+#             */
/*   Updated: 2019/03/26 14:13:58 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		init_diff(void *mlx)
{
	if (((t_mlx*)mlx)->mode == 1)
	{
		((t_mlx*)mlx)->ix = 224.0 / ((t_mlx*)mlx)->zoom;
		((t_mlx*)mlx)->iy = 224.0 / ((t_mlx*)mlx)->zoom;
	}
	else if (((t_mlx*)mlx)->mode == 2)
	{
		((t_mlx*)mlx)->ix = 243.0 / ((t_mlx*)mlx)->zoom;
		((t_mlx*)mlx)->iy = 216.0 / ((t_mlx*)mlx)->zoom;
	}
	else
	{
		((t_mlx*)mlx)->ix = 238.0 / ((t_mlx*)mlx)->zoom;
		((t_mlx*)mlx)->iy = 238.0 / ((t_mlx*)mlx)->zoom;
	}
}

static void	init_fract2(void *mlx)
{
	((t_mlx*)mlx)->x1 = -1.7;
	((t_mlx*)mlx)->x2 = 1.7;
	((t_mlx*)mlx)->y1 = -1.7;
	((t_mlx*)mlx)->y2 = 1.7;
	((t_mlx*)mlx)->zoom = 350;
	((t_mlx*)mlx)->itermax = 100;
}

void		init_fract(void *mlx)
{
	if (((t_mlx*)mlx)->mode == 1)
	{
		((t_mlx*)mlx)->x1 = -2;
		((t_mlx*)mlx)->x2 = 1.2;
		((t_mlx*)mlx)->y1 = -2.2;
		((t_mlx*)mlx)->y2 = 1;
		((t_mlx*)mlx)->zoom = 350;
		((t_mlx*)mlx)->itermax = 15;
	}
	else if (((t_mlx*)mlx)->mode == 2)
	{
		((t_mlx*)mlx)->x1 = -2.1;
		((t_mlx*)mlx)->x2 = 0.6;
		((t_mlx*)mlx)->y1 = -1.2;
		((t_mlx*)mlx)->y2 = 1.2;
		((t_mlx*)mlx)->zoom = 450;
		((t_mlx*)mlx)->itermax = 35;
	}
	else
		init_fract2(mlx);
	((t_mlx*)mlx)->colorset = 1;
}
