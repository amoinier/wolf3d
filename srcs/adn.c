/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/02 16:35:59 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

int	adn(t_env *init, double x1, double x2, double y1, double y2)
{
	double	size;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;

	size = fabs(y2 - y1);
	if (fabs(x2 - x1) >= size)
		size = fabs(x2 - x1);
	//printf("%f\n", size);
	dx = (x2 - x1) / size;
	dy = (y2 - y1) / size;
	x = x1 + 0.1;
	y = y1 + 0.1;
	i = 1;
	while (init->point[(int)y][(int)x]->z != 1)
	{
		x = x + dx;
		y = y + dy;
		i++;
	}
	//printf("%f - %f\n", x, y);
	init->distval = sqrt(fabs(x - x1) * fabs(x - x1) + fabs(y - y1) * fabs(y - y1));
	return (i);
}
