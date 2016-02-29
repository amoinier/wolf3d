/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/27 00:32:02 by amoinier         ###   ########.fr       */
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

	y = ((double)init->height / 2) - (sizewall / 2);
	while (y <= ((double)init->height / 2) + (sizewall / 2))
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
	ang = init->camangle - 30;
	scal = 60 / (double)init->width;
	while (ang <= init->camangle + 30)
	{
		dist_cam(init, (double)init->posinitx, (double)init->posinity, ang);
		sizewall = (double)init->height / (init->distval / 2);
		draw_wall(init, x, sizewall);
		x++;
		ang += scal;
	}
} 
