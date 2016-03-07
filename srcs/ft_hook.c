/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/07 17:35:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

int				mousecam(int x, int y, t_env *init)
{
	if (init->games == 1)
	{
		ft_clear_img(init);
		init->camangle = x * (2600 / 360) / 20;
		if (init->activey == 1)
		{
			init->camy = -(y + 200) * ((1440) / 100) / 20;
			if (init->camy >= 100)
				init->camy = 99;
			else if (init->camy <= -401)
				init->camy = -399;
		}
		raycaster(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		if (init->mapkey == 1)
		{
			drawmap(init);
			mlx_put_image_to_window(init->mlx, init->win, init->map->img,
			init->width - init->point[0][0]->sizecol * 5,
			init->height - init->point[0][0]->sizeline * 5);
		}
	}
	return (0);
}

static	void	move(int keycode, t_env *init)
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

static	void	load_map(t_env *init)
{
	if (init->point[(int)(init->posinity)][(int)(init->posinitx)]->z == 9)
	{
		free(init->point);
		init->point = NULL;
		init->point = ft_createstruct(init, selectmaps());
		if (init->posinitx == -1 || init->posinity == -1)
			error("error : posinitx == -1");
	}
}

int				key_hook(int keycode, t_env *init)
{
	ft_clear_img(init);
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		mlx_destroy_image(init->mlx, init->map->img);
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	if (init->games == 1)
	{
		load_map(init);
		move(keycode, init);
		raycaster(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		if (init->mapkey == 1)
		{
			drawmap(init);
			mlx_put_image_to_window(init->mlx, init->win, init->map->img,
			init->width - init->point[0][0]->sizecol * 5,
			init->height - init->point[0][0]->sizeline * 5);
		}
	}
	return (0);
}

int				expose_hook(t_env *init)
{
	if (init->games == 1)
	{
		raycaster(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		if (init->mapkey == 1)
		{
			drawmap(init);
			mlx_put_image_to_window(init->mlx, init->win, init->map->img,
			init->width - init->point[0][0]->sizecol * 5,
			init->height - init->point[0][0]->sizeline * 5);
		}
	}
	return (0);
}
