/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/04 15:15:41 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

void	color_code(t_env *init, double x, double y)
{
	if ((int)x > 0 && init->point[(int)y][(int)x - 1]->z != 1 && x - (int)x < 0.005)
		init->dist->color = 0xff0000;
	else if ((int)x < init->point[(int)y][0]->sizecol - 1 && init->point[(int)y][(int)x + 1]->z != 1 && x - (int)x > 0.995)
		init->dist->color = 0x00ff00;
	else if ((int)y > 0 && init->point[(int)y - 1][(int)x]->z != 1 && y - (int)y < 0.005)
		init->dist->color = 0xffed00;
	else if ((int)y < init->point[0][0]->sizeline - 1 && init->point[(int)y + 1][(int)x]->z != 1 && y - (int)y > 0.995)
		init->dist->color = 0x0000ff;
}

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
	size *= 200;
	dx = (x2 - x1) / size;
	dy = (y2 - y1) / size;
	x = x1 + 0.1;
	y = y1 + 0.1;
	while (init->point[(int)y][(int)x]->z != 1)
	{
		x += dx;
		y += dy;
	}
	color_code(init, x, y);
	init->dist->distval = sqrt(fabs(x - x1) * fabs(x - x1) + fabs(y - y1) * fabs(y - y1));
	return (init->dist->distval);
}
