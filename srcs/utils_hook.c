/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:46:56 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/08 12:51:42 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <math.h>

void	move(int keycode, t_env *init)
{
	double	sa;
	double	ca;

	if (keycode == 49 && init->run == 15)
		init->run = 5;
	else if (keycode == 49 && init->run == 5)
		init->run = 15;
	if (keycode == 51 && init->activey == 0)
		init->activey = 1;
	else if (keycode == 51 && init->activey == 1 && (init->camy = 0) == 0)
		init->activey = 0;
	if (keycode == 256 && init->mapkey == 0)
		init->mapkey = 1;
	else if (keycode == 256 && init->mapkey == 1)
		init->mapkey = 0;
	sa = sin(init->camangle * RAD) / init->run;
	ca = cos(init->camangle * RAD) / init->run;
	printf("%f - %f\n", init->posinitx, init->posinity);
	printf("%f - %f\n\n", ca, sa);
	utils(init, keycode, sa, ca);
}

void	load_map(t_env *init)
{
	if (init->point[(int)(init->posinity)][(int)(init->posinitx)]->z == 9)
	{
		free(init->point);
		init->point = NULL;
		init->point = ft_createstruct(init, selectmaps());
		if (init->posinitx == -1 || init->posinity == -1)
			error("error : posinitx == -1");
		init->posinity += 0.5;
		init->posinitx += 0.5;
	}
}
