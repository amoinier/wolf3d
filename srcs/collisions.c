/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:54:12 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/11 14:15:43 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

static	void	up(t_env *init, int keycode, double sa, double ca)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	if (sa < 0)
		x = -1;
	if (ca < 0)
		y = -1;
	if (keycode == 126)
	{
		if (init->point[(int)(init->posinity - sa * 2 - x * 0.1)]
		[(int)(init->posinitx)]->z != 1 &&
		init->point[(int)(init->posinity - sa)]
		[(int)(init->posinitx)]->z != 1)
			init->posinity -= sa;
		if (init->point[(int)(init->posinity)]
		[(int)(init->posinitx - ca * 2 - y * 0.1)]->z != 1 &&
		init->point[(int)(init->posinity)]
		[(int)(init->posinitx - ca)]->z != 1)
			init->posinitx -= ca;
	}
}

static	void	down(t_env *init, int keycode, double sa, double ca)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	if (sa < 0)
		x = -1;
	if (ca < 0)
		y = -1;
	if (keycode == 125)
	{
		if (init->point[(int)(init->posinity + sa * 2 + x * 0.1)]
		[(int)(init->posinitx)]->z != 1 &&
		init->point[(int)(init->posinity + sa)]
		[(int)(init->posinitx)]->z != 1)
			init->posinity += sa;
		if (init->point[(int)(init->posinity)]
		[(int)(init->posinitx + ca * 2 + y * 0.1)]->z != 1 &&
		init->point[(int)(init->posinity)]
		[(int)(init->posinitx + ca)]->z != 1)
			init->posinitx += ca;
	}
}

static	void	left(t_env *init, double ca, double sa)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	if (sa < 0)
		x = -1;
	if (ca < 0)
		y = -1;
	if (init->point[(int)(init->posinity + ca * 2 + y * 0.1)]
	[(int)(init->posinitx)]->z != 1 &&
	init->point[(int)(init->posinity + ca * 2 + y * 0.05)]
	[(int)(init->posinitx)]->z != 1 &&
	init->point[(int)(init->posinity + ca)]
	[(int)(init->posinitx)]->z != 1)
		init->posinity += ca;
	if (init->point[(int)(init->posinity)]
	[(int)(init->posinitx - sa * 2 - x * 0.1)]->z != 1 &&
	init->point[(int)(init->posinity)]
	[(int)(init->posinitx - sa * 2 - x * 0.05)]->z != 1 &&
	init->point[(int)(init->posinity)]
	[(int)(init->posinitx - sa)]->z != 1)
		init->posinitx -= sa;
}

static	void	right(t_env *init, double ca, double sa)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	if (sa < 0)
		x = -1;
	if (ca < 0)
		y = -1;
	if (init->point[(int)(init->posinity - ca * 2 - (y * 0.1))]
	[(int)(init->posinitx)]->z != 1 &&
	init->point[(int)(init->posinity - ca * 2 - (y * 0.05))]
	[(int)(init->posinitx)]->z != 1 &&
	init->point[(int)(init->posinity - ca)]
	[(int)(init->posinitx)]->z != 1)
		init->posinity -= ca;
	if (init->point[(int)(init->posinity)]
	[(int)(init->posinitx + (sa * 2) + (x * 0.1))]->z != 1 &&
	init->point[(int)(init->posinity)]
	[(int)(init->posinitx + (sa * 2) + (x * 0.05))]->z != 1 &&
	init->point[(int)(init->posinity)]
	[(int)(init->posinitx + sa)]->z != 1)
		init->posinitx += sa;
}

void			utils(t_env *init, int keycode, double sa, double ca)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	if (sa < 0)
		x = -1;
	if (ca < 0)
		y = -1;
	up(init, keycode, sa, ca);
	down(init, keycode, sa, ca);
	if (keycode == 123)
		left(init, ca, sa);
	if (keycode == 124)
		right(init, ca, sa);
}
