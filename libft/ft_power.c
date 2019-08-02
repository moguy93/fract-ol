/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:20:13 by moguy             #+#    #+#             */
/*   Updated: 2019/03/22 17:42:54 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	modulus(double a, double b)
{
	return (sqrt(a * a + b * b));
}

int		ft_power(int nb, int power)
{
	int result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	power--;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
