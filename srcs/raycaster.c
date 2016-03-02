/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/02 20:31:45 by amoinier         ###   ########.fr       */
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
	x2 = xcam - (20 * ca);
	y2 = ycam - (20 * sa);
	adn(init, xcam, x2, ycam, y2);
	return (adn(init, xcam, x2, ycam, y2));
}

double		dist_ver(t_env *init, double xcam, double ycam, double angle)
{
	double	bx;
	double	by;
	double	xa;
	double	ya;
	double	x2;
	double	y2;

	if (angle < 90 && angle > 270)
	{
		bx = (xcam/64) * (64) + 64;
		xa = 64;
	}
	else
	{
		bx = (xcam/64) * (64) - 1;
		xa = -64;
	}
	ya = (64 * tan(angle * (PI / 180)));
	by = ycam + (xcam - bx) * tan(angle * (PI / 180));
	x2 = bx + (20 * xa);
	y2 = by + (20 * ya);
	return (adn(init, xcam, x2, ycam, y2));
}

void	draw_wall(t_env *init, int x, double sizewall)
{
	double	y;

	y = ((double)init->height / 2.0000) - (sizewall / 2.0000);
	//printf("%f\n", y);
	while (y <= ((double)init->height / 2.0000) + (sizewall / 2.0000))
	{
		pixel_put_image(init, x, y, 0x5b0202);
		y++;
	}
}

void	raycaster(t_env *init)
{
	int		x;
	double	ang;
	double	sizewall;
	double	scal;
	double	i;
	double 	j;

	x = 0;
	ang = init->camangle - 30.0000;
	scal = 60.0000 / (double)init->width;
	while (x <= init->width)
	{
		i = 0;
		//i = dist_hor(init, (double)init->posinitx, (double)init->posinity, ang);
		j = dist_ver(init, (double)init->posinitx, (double)init->posinity, ang);
		//printf("%f - %f\n", i, j);
		if (j <= i)
			i = j;
		sizewall = (double)init->height / (j);
		//printf("%f\n", sizewall);
		draw_wall(init, x, sizewall);
		x++;
		ang += scal;
	}
}
