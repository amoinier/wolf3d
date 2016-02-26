/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/27 00:32:05 by amoinier         ###   ########.fr       */
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

	//printf("%f - %f - %f - %f\n\n", x1, x2, y1, y2);
	if (fabs(x2 - x1) >= fabs(y2 - y1))
		size = fabs(x2 - x1);
	else
		size = fabs(y2 - y1);
	dx = (x2 - x1) / size;
	dy = (y2 - y1) / size;
	x = x1 + 0.5;
	y = y1 + 0.5;
	i = 1;
	while (init->point[(int)y][(int)x]->z != 1)
	{
		x = x + dx;
		y = y + dy;
		i++;
	}
	//printf("%f - %f\n", y1, y2);
	init->distval = sqrt(fabs(x - x1) * fabs(x - x1) + fabs(y - y1) * fabs(y - y1));
	if (x1 - x2 == 0)
		init->distval = fabs(y - y1);
	else if (y1 - y2 == 0)
		init->distval = fabs(x - x1);
	if (init->distval < 2)
		init->distval = 2;
	return (i);
}
