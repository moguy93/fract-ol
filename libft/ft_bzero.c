/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:06:15 by moguy             #+#    #+#             */
/*   Updated: 2019/02/14 06:08:55 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;
	int		i;

	b = (char*)s;
	i = n - 1;
	while (i >= 0)
	{
		b[i] = '\0';
		if ((i - 1) >= 0)
			b[i - 1] = '\0';
		if ((i - 2) >= 0)
			b[i - 2] = '\0';
		if ((i - 3) >= 0)
			b[i - 3] = '\0';
		if ((i - 4) >= 0)
			b[i - 4] = '\0';
		if ((i - 5) >= 0)
			b[i - 5] = '\0';
		if ((i - 6) >= 0)
			b[i - 6] = '\0';
		if ((i - 7) >= 0)
			b[i - 7] = '\0';
		i -= 7;
	}
}