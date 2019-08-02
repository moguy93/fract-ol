/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:01:14 by moguy             #+#    #+#             */
/*   Updated: 2019/03/26 16:49:04 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	ft_usage2(void)
{
	ft_putstr("usage: ./fractol [fractale_name]\n");
	ft_putstr("[mandelbrot] [julia] [burningship]\n");
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_SUCCESS);
}
