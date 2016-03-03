/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/03 17:34:56 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
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
		init->camangle -= 3;
	if (keycode == 14)
		init->camangle += 3;
}

int				key_hook(int keycode, t_env *init)
{
	double	sa;
	double	ca;

	sa = sin(init->camangle * (PI / 180)) / 5;
	ca = cos(init->camangle * (PI / 180)) / 5;
	ft_clear_img(init);
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	printf("%f - %f\n", sa, ca);
	if (keycode == 126 && init->point[(int)(init->posinity - (sa * 5))][(int)(init->posinitx - (ca * 5))]->z != 1)
	{
		init->posinity -= sa;
		init->posinitx -= ca;
	}
	if (keycode == 125 && init->point[(int)(init->posinity + (sa * 5))][(int)(init->posinitx + (ca * 5))]->z != 1)
	{
		init->posinity += sa;
		init->posinitx += ca;
	}
	if (keycode == 123 && init->point[(int)(init->posinity + (ca * 5))][(int)(init->posinitx - (sa * 5))]->z != 1)
	{
		init->posinity += ca;
		init->posinitx -= sa;
	}
	if (keycode == 124 && init->point[(int)(init->posinity - (ca * 5))][(int)(init->posinitx + (sa * 5))]->z != 1)
	{
		init->posinity -= ca;
		init->posinitx += sa;
	}
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
