/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/23 16:51:14 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
/*
int				mouse_hook(int button, int x, int y, t_env *init)
{
	return (0);
}

int				mouse(int x, int y, t_env *init)
{
	return (0);
}*/

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
	raycaster(init, init->point);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}
/*
int				expose_hook(t_env *init)
{
	return (0);
}*/
