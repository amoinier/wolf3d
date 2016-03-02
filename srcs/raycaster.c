/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/02 16:19:33 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

int		dist_cam(t_env *init, double xcam, double ycam, double angle)
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
	x2 = xcam - (20 * ca);
	y2 = ycam - (20 * sa);
	adnv = adn(init, xcam, x2, ycam, y2);
	dist = sqrt((sa * sa) + (ca * ca)) * adnv;
	return (adnv);
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

	x = 0;
	ang = init->camangle - 30.0000;
	scal = 60.0000 / (double)init->width;
	while (x <= init->width)
	{
		dist_cam(init, (double)init->posinitx, (double)init->posinity, ang);
		sizewall = (double)init->height / (init->distval);
		//printf("%f\n", sizewall);
		draw_wall(init, x, sizewall);
		x++;
		ang += scal;
	}
}
