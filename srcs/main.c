/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:24:31 by moguy             #+#    #+#             */
/*   Updated: 2019/07/13 03:21:57 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	init_pack(t_mlx *mlx)
{
	if (mlx->mode == 1)
	{
		mlx->width = 1120;
		mlx->heigth = 1120;
	}
	if (mlx->mode == 2)
	{
		mlx->width = 1215;
		mlx->heigth = 1080;
	}
	if (mlx->mode == 3)
	{
		mlx->width = 1190;
		mlx->heigth = 1190;
	}
	mlx->onoff = 0;
	mlx->nlt = 0;
}

static void	init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		ft_error();
	if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->heigth, "Frct")))
		ft_error();
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->heigth);
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->siz),
			&(mlx->end));
	init_fract(mlx);
	threader(mlx);
}

static int	ft_mode(char **argv)
{
	int		mode;

	mode = 0;
	if (ft_strcmp(argv[1], "burningship") != 0
			&& ft_strcmp(argv[1], "mandelbrot") != 0
			&& ft_strcmp(argv[1], "julia") != 0)
		ft_usage2();
	if (ft_strcmp(argv[1], "burningship") == 0)
		mode = 1;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mode = 2;
	else if (ft_strcmp(argv[1], "julia") == 0)
		mode = 3;
	return (mode);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	void	*exit;

	if (argc != 2)
		ft_usage2();
	exit = &deal_exit;
	mlx.mode = ft_mode(argv);
	init_pack(&mlx);
	init_mlx(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, deal_key2, &mlx);
	mlx_mouse_hook(mlx.win, deal_mouse3, &mlx);
	if (mlx.mode == 3)
		mlx_hook(mlx.win, 6, 0, deal_move2, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit, &mlx);
	mlx_loop_hook(mlx.mlx, deal_loop, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
