/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:32:29 by moguy             #+#    #+#             */
/*   Updated: 2019/05/21 19:19:53 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	deal_exit(void *mlx)
{
	mlx_destroy_image(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->img);
	mlx_destroy_window(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win);
	exit(EXIT_SUCCESS);
}

void	deal_arrow(void *mlx, int key)
{
	if (key == 123 && ((t_mlx*)mlx)->x1 > -2.5)
	{
		((t_mlx*)mlx)->x1 -= ((t_mlx*)mlx)->ix;
		((t_mlx*)mlx)->x2 -= ((t_mlx*)mlx)->ix;
	}
	else if (key == 124 && ((t_mlx*)mlx)->x2 < 2)
	{
		((t_mlx*)mlx)->x1 += ((t_mlx*)mlx)->ix;
		((t_mlx*)mlx)->x2 += ((t_mlx*)mlx)->ix;
	}
	else if (key == 125 && ((t_mlx*)mlx)->y2 < 2)
	{
		((t_mlx*)mlx)->y1 += ((t_mlx*)mlx)->iy;
		((t_mlx*)mlx)->y2 += ((t_mlx*)mlx)->iy;
	}
	else if (key == 126 && ((t_mlx*)mlx)->y1 > -2.5)
	{
		((t_mlx*)mlx)->y1 -= ((t_mlx*)mlx)->iy;
		((t_mlx*)mlx)->y2 -= ((t_mlx*)mlx)->iy;
	}
}

void	deal_color(void *mlx)
{
	if (((t_mlx*)mlx)->colorset < 7)
		((t_mlx*)mlx)->colorset += 1;
	else
		((t_mlx*)mlx)->colorset = 0;
}

int		deal_mouse3(int key, int x, int y, void *mlx)
{
	((t_mlx*)mlx)->keymouse = key;
	((t_mlx*)mlx)->xmouse = x;
	((t_mlx*)mlx)->ymouse = y;
	return (0);
}

int		deal_loop(void *mlx)
{
	if (((t_mlx*)mlx)->keymouse != 0)
	{
		if (((t_mlx*)mlx)->keymouse == 4)
			deal_mouse(mlx);
		else if (((t_mlx*)mlx)->keymouse == 5)
			deal_mouse2(mlx);
		((t_mlx*)mlx)->keymouse = 0;
	}
	else if (((t_mlx*)mlx)->keyboard != 0)
	{
		deal_key(((t_mlx*)mlx)->keyboard, mlx);
		((t_mlx*)mlx)->keyboard = 0;
	}
	else if (((t_mlx*)mlx)->xmove != 0)
	{
		deal_move(mlx);
		((t_mlx*)mlx)->xmove = 0;
	}
	return (0);
}
