/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/25 21:17:42 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

int		dist_cam(t_env *init, double xcam, double ycam, int angle)
{
	double	sa;
	double	ca;
	double	x2;
	double	y2;
	int		step;
	double	dist;
	int		adnv;

	sa = sin(angle * (PI / 180));
	ca = cos(angle * (PI / 180));
	step = 0;
	x2 = xcam - (10 * ca);
	y2 = ycam - (10 * sa);
	if (x2 < 0)
		x2 = 0;
	if (y2 < 0)
		y2 = 0;
	adnv = adn(init, xcam, x2, ycam, y2);
	dist = sqrt((sa * sa) + (ca * ca)) * adnv;
	return (adnv);
}

void	draw_wall(t_env *init, int x, double sizewall)
{
	int	y;
	int	x2;

	x2 = x;
	while (x2 <= x + 64)
	{
		y = ((double)init->height / 2) - (sizewall / 2);
		while (y <= ((double)init->height / 2) + (sizewall / 2))
		{
			pixel_put_image(init, x2, y, 0x5b0202);
			y++;
		}
		x2++;
	}
}

void	raycaster(t_env *init)
{
	int		x;
	int		ang;
	double	sizewall;

	x = 0;
	ang = init->camangle - 30;
	while (ang <= init->camangle + 30)
	{
		dist_cam(init, (double)init->posinitx, (double)init->posinity, ang);
		if (init->distval < 2)
			init->distval = 2;
		sizewall = (double)init->height / (init->distval / 2);
		//printf("%f\n", sizewall);
		draw_wall(init, x, sizewall);
		x += (init->width / 60);
		ang++;
	}
}
