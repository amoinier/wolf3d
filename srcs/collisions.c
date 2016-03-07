/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:54:12 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/07 17:35:11 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

static	int		collision_sa(t_env *init, double sa, double ca, int keycode)
{
	ca *= 1;
	if (keycode == 126)
	{
		if (init->point[(int)(init->posinity - (sa * 2))]
		[(int)(init->posinitx - ca)]->z != 1)
			return (1);
	}
	else if (keycode == 125)
	{
		if (init->point[(int)(init->posinity + (sa * 2))]
		[(int)(init->posinitx - ca)]->z != 1)
			return (1);
	}
	else if (keycode == 123)
	{
		if (init->point[(int)(init->posinity - ca)]
		[(int)(init->posinitx - (sa * 2))]->z != 1)
			return (1);
	}
	else if (keycode == 124)
	{
		if (init->point[(int)(init->posinity - ca)]
		[(int)(init->posinitx + (sa * 2))]->z != 1)
			return (1);
	}
	return (0);
}

static	int		collision_ca(t_env *init, double ca, double sa, int keycode)
{
	sa *= 1;
	if (keycode == 126)
	{
		if (init->point[(int)(init->posinity - sa)]
		[(int)(init->posinitx - (ca * 2))]->z != 1)
			return (1);
	}
	else if (keycode == 125)
	{
		if (init->point[(int)(init->posinity - sa)]
		[(int)(init->posinitx + (ca * 2))]->z != 1)
			return (1);
	}
	else if (keycode == 123)
	{
		if (init->point[(int)(init->posinity + (ca * 2))]
		[(int)(init->posinitx - sa)]->z != 1)
			return (1);
	}
	else if (keycode == 124)
	{
		if (init->point[(int)(init->posinity - (ca * 2))]
		[(int)(init->posinitx - sa)]->z != 1)
			return (1);
	}
	return (0);
}

static	void	up_down(t_env *init, int keycode, double sa, double ca)
{
	if (keycode == 126)
	{
		if (collision_sa(init, sa, ca, keycode))
			init->posinity -= sa;
		if (collision_ca(init, ca, sa, keycode))
			init->posinitx -= ca;
	}
	if (keycode == 125)
	{
		if (collision_sa(init, sa, ca, keycode))
			init->posinity += sa;
		if (collision_ca(init, ca, sa, keycode))
			init->posinitx += ca;
	}
}

void			utils(t_env *init, int keycode, double sa, double ca)
{
	up_down(init, keycode, sa, ca);
	if (keycode == 123)
	{
		if (collision_ca(init, ca, sa, keycode))
			init->posinity += ca;
		if (collision_sa(init, sa, ca, keycode))
			init->posinitx -= sa;
	}
	if (keycode == 124)
	{
		if (collision_ca(init, ca, sa, keycode))
			init->posinity -= ca;
		if (collision_sa(init, sa, ca, keycode))
			init->posinitx += sa;
	}
}
