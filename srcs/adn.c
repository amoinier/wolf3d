/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/03 14:35:57 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

double	adn(t_env *init, double x1, double x2, double y1, double y2)
{
	double	size;
	double	dx;
	double	dy;
	double	x;
	double	y;

	size = fabs(y2 - y1);
	if (fabs(x2 - x1) >= size)
		size = fabs(x2 - x1);
	//printf("%f\n", size);
	dx = (x2 - x1) / size / 200;
	dy = (y2 - y1) / size / 200 ;
	x = x1 + 0.1;
	y = y1 + 0.1;
	//printf("%f\n\n", dx);
	while (init->point[(int)y][(int)x]->z != 1)
	{
		x += dx;
		y += dy;
	}
	init->distval = sqrt(fabs(x - x1) * fabs(x - x1) + fabs(y - y1) * fabs(y - y1));
	//printf("%f\n", init->distval);
	return (init->distval);
}
