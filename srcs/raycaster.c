/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/25 18:11:22 by amoinier         ###   ########.fr       */
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
	adnv = adn(init, xcam, x2, ycam, y2);
	dist = sqrt((sa * sa) + (ca * ca)) * adnv;
	return (adnv);
}

void	draw_sky(t_env *init, int x, int sizewall)
{
	int	y;
	int	x2;

	x2 = x;
	while (x2 <= x + 64)
	{
		y = 0;
		while (y <= (init->height / 2) - (sizewall / 2))
		{
			pixel_put_image(init, x2, y, 0x1272af);
			y++;
		}
		x2++;
	}
}

void	draw_wall(t_env *init, int x, int sizewall)
{
	int	y;
	int	x2;

	x2 = x;
	while (x2 <= x + 64)
	{
		y = (init->height / 2) - (sizewall / 2);
		while (y <= (init->height / 2) + (sizewall / 2))
		{
			pixel_put_image(init, x2, y, 0x5b0202);
			y++;
		}
		x2++;
	}
}

void	draw_floor(t_env *init, int x, int sizewall)
{
	int	y;
	int	x2;

	x2 = x;
	while (x2 <= x + 64)
	{
		y = (init->height / 2) + (sizewall / 2);
		while (y <= init->height)
		{
			pixel_put_image(init, x2, y, 0x373737);
			y++;
		}
		x2++;
	}
}

void	raycaster(t_env *init)
{
	int	x;
	int	sizewall;
	int	dist;
	int	ang;

	x = 0;
	ang = 0;
	while (ang <= 60)
	{
		dist = (dist_cam(init, (double)init->posinitx, (double)init->posinity, init->camangle - 30 + ang));
		if (dist <= 0)
			dist = 1;
		sizewall = init->height / dist;
		draw_sky(init, x, sizewall);
		draw_floor(init, x, sizewall);
		draw_wall(init, x, sizewall);
		x += (init->width / 60);
		ang++;
	}
}
