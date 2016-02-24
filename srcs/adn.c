/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:51:18 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/24 12:29:44 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

int	adn(t_env *init, float x1, float x2, float y1, float y2)
{
	float	size;
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		i;

	init->height = 800;
	if (fabs(x2 - x1) >= fabs(y2 - y1))
		size = fabs(x2 - x1);
	else
		size = fabs(y2 - y1);
	dx = (x2 - x1) / size;
	dy = (y2 - y1) / size;
	x = x1 + 0.5;
	y = y1 + 0.5;
	i = 1;
	while (i < size)
	{
		//setPixel ( E ( x ), E ( y ) )
		x = x + dx;
		y = y + dy;
		i++;
	}
	return (0);
}
