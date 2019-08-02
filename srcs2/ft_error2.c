/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:01:14 by moguy             #+#    #+#             */
/*   Updated: 2019/03/26 16:44:06 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		deal_exit2(int key, void *mlx)
{
	if (key == 53)
	{
		mlx_destroy_image(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->img);
		mlx_destroy_window(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_usage(void)
{
	ft_putstr("usage: ./fractol [fractale_name]\n");
	ft_putstr("[mandelbrot] [julia] [burningship]\n");
	exit(EXIT_SUCCESS);
}

void	ft_error2(void)
{
	ft_putstr("error\n");
	exit(EXIT_SUCCESS);
}

void	ft_buttons(void *mlx)
{
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 25, 0x00ffffff,
			"touches et fonctions:\n\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 50, 0x00ffffff,
			"fleches: pour se deplacer.\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 75, 0x00ffffff,
			"'b', 'n', '-', '+', ',', '.', '*', '/': ");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 100, 0x00ffffff,
			"reduit et augmente la precision");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 125, 0x00ffffff,
			" de respectivement 5, 20, 100 et 1000.\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 150, 0x00ffffff,
			"'c': fait tourner la palette de couleurs.\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 175, 0x00ffffff,
			"'esc': ferme le programme.\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 200, 0x00ffffff,
			"'tab': reinitialise la fractale.\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 225, 0x00ffffff,
			"'l': leve la limite d'iteration.\n");
	mlx_string_put(((t_mlx*)mlx)->mlx, ((t_mlx*)mlx)->win, 20, 250, 0x00ffffff,
			"'o': bloque les variations de julia que la souris effectue.\n");
}
