/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/25 16:35:19 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

int	adn(t_point ***point, double x1, double x2, double y1, double y2)
{
	double	size;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;

	if (fabs(x2 - x1) >= fabs(y2 - y1))
		size = fabs(x2 - x1);
	else
		size = fabs(y2 - y1);
	dx = (x2 - x1) / size;
	dy = (y2 - y1) / size;
	x = x1 + 0.5;
	y = y1 + 0.5;
	i = 1;
	while (point[(int)y][(int)x]->z != 1)
	{
		x = x + dx;
		y = y + dy;
		printf("%f - %f\n", x, y);
		i++;
	}
	return (i);
}
