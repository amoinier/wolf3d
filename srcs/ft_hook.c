/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:12:54 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/04 18:02:32 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

int				mousecam(int x, int y, t_env *init)
{
	ft_clear_img(init);
	init->camangle = x * (2600 / 360) / 20;
	if (init->camangle == 360)
		init->camangle = 0;
	else if (init->camangle == 0)
		init->camangle = 360;
	init->camy = -(y + 200) * ((1440) / 100) / 20;
	if (init->camy >= 100)
		init->camy = 99;
	else if (init->camy <= -401)
		init->camy = -399;
	raycaster(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

void	move(int keycode, t_env *init)
{
	double	sa;
	double	ca;

	sa = sin(init->camangle * (PI / 180)) / 5;
	ca = cos(init->camangle * (PI / 180)) / 5;
	if (keycode == 126 && init->point[(int)(init->posinity - (sa * 3))][(int)(init->posinitx - (ca * 3))]->z != 1)
	{
		init->posinity -= sa;
		init->posinitx -= ca;
	}
	if (keycode == 125 && init->point[(int)(init->posinity + (sa * 3))][(int)(init->posinitx + (ca * 3))]->z != 1)
	{
		init->posinity += sa;
		init->posinitx += ca;
	}
	if (keycode == 123 && init->point[(int)(init->posinity + (ca * 3))][(int)(init->posinitx - (sa * 3))]->z != 1)
	{
		init->posinity += ca;
		init->posinitx -= sa;
	}
	if (keycode == 124 && init->point[(int)(init->posinity - (ca * 3))][(int)(init->posinitx + (sa * 3))]->z != 1)
	{
		init->posinity -= ca;
		init->posinitx += sa;
	}
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
	move(keycode, init);
	raycaster(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	return (0);
}

int				expose_hook(t_env *init)
{
	raycaster(init);
	return (0);
}
