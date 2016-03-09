/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/09 11:29:06 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <time.h>

int				mouse_hook(int x, int y, t_env *init)
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

int				loop_hook(t_env *init)
{
	static	int	x = 0;
	char		*ttime;

	if (ft_strequ(init->name, "map/end") && x == 0)
	{
		ttime = ft_itoa(time(NULL) - init->start_time);
		ft_clear_img(init);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		init->games = 0;
		mlx_string_put(init->mlx, init->win, init->width / 2 - 140,
		init->height / 2, 0xffffff, "Vous avez finis le jeux en ");
		mlx_string_put(init->mlx, init->win, init->width / 2 + 130,
		init->height / 2, 0xffffff, ttime);
		mlx_string_put(init->mlx, init->win, init->width / 2 - 40,
		init->height / 2 + 20, 0xffffff, "secondes !");
		mlx_string_put(init->mlx, init->win, init->width / 2 - 150,
		init->height / 2 + 40, 0xff0000, "Appuyez sur [ESC] pour quitter");
		free(ttime);
		x++;
	}
	return (0);
}
