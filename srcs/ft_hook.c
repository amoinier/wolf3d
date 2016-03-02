/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/02 18:38:07 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
/*
int				mouse_hook(int button, int x, int y, t_env *init)
{
	return (0);
}

int				mouse(int x, int y, t_env *init)
{
	return (0);
}*/

void	camera_move(int keycode, t_env *init)
{
	if (init->camangle == 360)
		init->camangle = 0;
	else if (init->camangle == 0)
		init->camangle = 360;
	if (keycode == 12)
		init->camangle -= 5;
	if (keycode == 14)
		init->camangle += 5;
}

int				key_hook(int keycode, t_env *init)
{
	ft_clear_img(init);
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	if (keycode == 126 && init->point[init->posinity - 1][init->posinitx]->z != 1)
		init->posinity--;
	if (keycode == 125 && init->point[init->posinity + 1][init->posinitx]->z != 1)
		init->posinity++;
	if (keycode == 123 && init->point[init->posinity][init->posinitx - 1]->z != 1)
		init->posinitx--;
	if (keycode == 124 && init->point[init->posinity][init->posinitx + 1]->z != 1)
		init->posinitx++;
	camera_move(keycode, init);
	raycaster(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

int				expose_hook(t_env *init)
{
	raycaster(init);
	return (0);
}
