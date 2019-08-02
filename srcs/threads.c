/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:22:20 by moguy             #+#    #+#             */
/*   Updated: 2019/07/13 03:21:00 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	threader(void *mlx)
{
	int			i;
	void		*fract_oil;

	i = 0;
	fract_oil = &fract_ol;
	init_diff(mlx);
	while (i < 4)
	{
		pthread_create(&(((t_mlx*)mlx)->thread[i]), NULL, fract_oil, mlx);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(((t_mlx*)mlx)->thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win,
			((t_mlx*)mlx)->img, 0, 0);
}

int		get_thread(pthread_t id, void *mlx)
{
	int		i;

	i = 0;
	while (i < 4 && !pthread_equal(id, ((t_mlx*)mlx)->thread[i]))
		i++;
	return (i);
}
