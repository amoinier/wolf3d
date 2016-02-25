/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/25 17:08:49 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

int		dist_cam(t_point ***point, double xcam, double ycam, int angle)
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
	adnv = adn(point, xcam, x2, ycam, y2);
	dist = sqrt((sa * sa) + (ca * ca)) * adnv;
	printf("\n%f\n\n", dist);
	return (adnv);
}

void	draw_sky(t_env *init, int x, int sizewall)
{
	int	y;

	y = 0;
	while (y <= (init->height / 2) - (sizewall / 2))
	{
		pixel_put_image(init, x, y, 0x1272af);
		y++;
	}
}

void	draw_wall(t_env *init, int x, int sizewall)
{
	int	y;
	int	x2;

	y = (init->height / 2) - (sizewall / 2);
	x2 = x;
	while (x2 <= x + 64)
	{
		while (y <= (init->height / 2) + (sizewall / 2))
		{
			pixel_put_image(init, x2, y, 0x5b0202);
			y++;
		}
		x2++;
		//y = (init->height / 2) - (sizewall / 2) - 1;
	}
}

void	draw_floor(t_env *init, int x, int sizewall)
{
	int	y;

	y = (init->height / 2) + (sizewall / 2);
	while (y <= init->height)
	{
		pixel_put_image(init, x, y, 0x373737);
		y++;
	}
}

void	raycaster(t_env *init, t_point ***point)
{
	int	x;
	int	sizewall;
	int	dist;
	int	ang;

	x = 0;
	ang = 0;
	while (ang <= 60)
	{
		dist = (dist_cam(point, (double)init->posinitx, (double)init->posinity, init->camangle - 30 + ang));
		if (dist <= 0)
			dist = 1;
		sizewall = init->height / dist;
		draw_wall(init, x, sizewall);
		//draw_sky(init, x, sizewall);
		//draw_floor(init, x, sizewall);
		x += (init->width / 60);
		ang++;
	}
}
