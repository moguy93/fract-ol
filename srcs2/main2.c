/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 04:24:31 by moguy             #+#    #+#             */
/*   Updated: 2019/04/02 11:56:14 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static int	ft_mode(int argc, char **argv, void *mlx)
{
	if (ft_strcmp(argv[1], "burningship") == 0
			|| ft_strcmp(argv[1], "mandelbrot") == 0
			|| ft_strcmp(argv[1], "julia") == 0)
		((t_mlx*)mlx)->mode = 1;
	else
		ft_usage();
	if (argc > 2)
	{
		if (ft_strcmp(argv[2], "burningship") == 0
				|| ft_strcmp(argv[2], "mandelbrot") == 0
				|| ft_strcmp(argv[2], "julia") == 0)
			((t_mlx*)mlx)->mode2 = 1;
		else
			ft_usage();
	}
	if (argc > 3)
	{
		if (ft_strcmp(argv[3], "burningship") == 0
				|| ft_strcmp(argv[3], "mandelbrot") == 0
				|| ft_strcmp(argv[3], "julia") == 0)
			((t_mlx*)mlx)->mode3 = 1;
		else
			ft_usage();
	}
	return (0);
}

static void	deal_close(void *mlx)
{
	mlx_destroy_image(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->img);
	mlx_destroy_window(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win);
	exit(EXIT_SUCCESS);
}

static void	launch_buttons(void *mlx)
{
	void	*close;

	((t_mlx*)mlx)->width = 700;
	((t_mlx*)mlx)->heigth = 400;
	close = &deal_close;
	if (!(((t_mlx*)mlx)->mlx = mlx_init()))
		ft_error2();
	if (!(((t_mlx*)mlx)->win = mlx_new_window(((t_mlx*)mlx)->mlx,
					((t_mlx*)mlx)->width, ((t_mlx*)mlx)->heigth, "Frct")))
		ft_error2();
	((t_mlx*)mlx)->img = mlx_new_image(((t_mlx*)mlx)->mlx,
		((t_mlx*)mlx)->width, ((t_mlx*)mlx)->heigth);
	((t_mlx*)mlx)->data = mlx_get_data_addr(((t_mlx*)mlx)->img,
		&(((t_mlx*)mlx)->bpp), &(((t_mlx*)mlx)->siz), &(((t_mlx*)mlx)->end));
	ft_buttons(mlx);
	mlx_key_hook(((t_mlx*)mlx)->win, deal_exit2, mlx);
	mlx_hook(((t_mlx*)mlx)->win, 17, 1L << 17, close, mlx);
	mlx_loop(((t_mlx*)mlx)->mlx);
}

static void	ft_fork(int ac, void **av, void *mlx)
{
	pid_t	*son;
	char	*arg[3];
	int		i;

	i = 0;
	if (!(son = (pid_t*)malloc(sizeof(pid_t) * (ac - 1))))
		ft_error2();
	while (i < (ac - 1))
	{
		arg[0] = "./fract ";
		arg[1] = av[i + 1];
		arg[2] = NULL;
		son[i] = fork();
		if (son[i] == 0)
			execv("./fract", arg);
		i++;
	}
	launch_buttons(mlx);
	i = 0;
	while (i < (ac - 1))
	{
		wait(son + i);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2 || argc > 5)
		ft_usage();
	mlx.mode = 0;
	mlx.mode2 = 0;
	mlx.mode3 = 0;
	ft_mode(argc, argv, &mlx);
	ft_fork(argc, (void**)argv, &mlx);
	return (0);
}
