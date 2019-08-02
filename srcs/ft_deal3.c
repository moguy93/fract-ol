/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 23:50:00 by moguy             #+#    #+#             */
/*   Updated: 2019/04/24 16:17:38 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	fill_pixel(void *mlx, int color, int *x, int *y)
{
	int		pos;

	pos = (*y * ((t_mlx*)mlx)->width + *x) * 4;
	((t_mlx*)mlx)->data[pos] = color >> 16 & 255;
	((t_mlx*)mlx)->data[pos + 1] = color >> 8 & 255;
	((t_mlx*)mlx)->data[pos + 2] = color & 255;
}

int		deal_move2(int x, int y, void *mlx)
{
	((t_mlx*)mlx)->xmove = x;
	((t_mlx*)mlx)->ymove = y;
	return (0);
}

int		deal_key2(int key, void *mlx)
{
	if (key == 37)
		((t_mlx*)mlx)->nlt = (((t_mlx*)mlx)->nlt == 0) ? 1 : 0;
	else
		((t_mlx*)mlx)->keyboard = key;
	return (0);
}
