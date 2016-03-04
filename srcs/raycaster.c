/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/04 15:02:47 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

double		dist_hor(t_env *init, double xcam, double ycam, double angle)
{
	double	sa;
	double	ca;
	double	x2;
	double	y2;

	sa = sin(angle * (PI / 180));
	ca = cos(angle * (PI / 180));
	x2 = xcam - (30 * ca);
	y2 = ycam - (30 * sa);
	adn(init, xcam, x2, ycam, y2);
	return (adn(init, xcam, x2, ycam, y2));
}

void	draw_sky(t_env *init, int x, double sizewall)
{
	int	y;

	y = rand() % (init->height / 2) - (sizewall / 2);
	pixel_put_image(init, x, y, 0xffffff);
}

void	draw_wall(t_env *init, int x, double sizewall)
{
	int	y;

	y = (init->height / 2) - (sizewall / 2);
	while (y <= (init->height / 2) + (sizewall / 2))
	{
		pixel_put_image(init, x, y, init->dist->color);
		y++;
	}
}

void	draw_floor(t_env *init, int x, double sizewall)
{
	int	y;

	y = (init->height / 2) + (sizewall / 2);
	while (y <= init->height)
	{
		pixel_put_image(init, x, y, 0x2a2828);
		y++;
	}
}

void	raycaster(t_env *init)
{
	int		x;
	double	ang;
	double	sizewall;
	double	scal;
	double 	distval;

	x = 0;
	ang = init->camangle - 30;
	scal = 60 / (double)init->width;
	while (x <= init->width)
	{
		distval = dist_hor(init, (double)init->posinitx, (double)init->posinity, ang);
		sizewall = (double)init->height / (distval);
		draw_wall(init, x, sizewall);
		draw_sky(init, x, sizewall);
		draw_floor(init, x, sizewall);
		x++;
		ang += scal;
	}
}
