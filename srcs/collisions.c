/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:54:12 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/06 16:32:42 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
//ca = -
//posx = <10

int		collision_sa(t_env *init, double sa, double ca, int keycode)
{
	if (keycode == 126)
	{
		if (init->point[(int)(init->posinity - (sa * 4))]
		[(int)(init->posinitx - ca * 2)]->z != 1)
			return (1);
	}
	else if (keycode == 125)
	{
		if (init->point[(int)(init->posinity + (sa * 4))]
		[(int)(init->posinitx + ca * 2)]->z != 1)
			return (1);
	}
	else if (keycode == 123)
	{
		if (init->point[(int)(init->posinity + ca * 2)]
		[(int)(init->posinitx - (sa * 4))]->z != 1)
			return (1);
	}
	else if (keycode == 124)
	{
		if (init->point[(int)(init->posinity - ca * 2)]
		[(int)(init->posinitx + (sa * 4))]->z != 1)
			return (1);
	}
	return (0);
}

int		collision_ca(t_env *init, double ca, double sa, int keycode)
{
	if (keycode == 126)
	{
		if (init->point[(int)(init->posinity - sa * 2)]
		[(int)(init->posinitx - (ca * 4))]->z != 1)
			return (1);
	}
	else if (keycode == 125)
	{
		if (init->point[(int)(init->posinity + sa * 2)]
		[(int)(init->posinitx + (ca * 4))]->z != 1)
			return (1);
	}
	else if (keycode == 123)
	{
		if (init->point[(int)(init->posinity + (ca * 4))]
		[(int)(init->posinitx - sa * 2)]->z != 1)
			return (1);
	}
	else if (keycode == 124)
	{
		if (init->point[(int)(init->posinity - (ca * 4))]
		[(int)(init->posinitx + sa * 2)]->z != 1)
			return (1);
	}
	return (0);
}
