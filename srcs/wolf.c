/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/04 18:12:36 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	t_img	*ft_init_img(t_env *init)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error("error : ft_init_img");
	img->img = mlx_new_image(init->mlx, init->width, init->height);
	img->bpp = 0;
	img->sizel = 0;
	img->endn = 0;
	img->cimg = mlx_get_data_addr(img->img, &img->bpp, &img->sizel, &img->endn);
	return (img);
}

static	void	ft_initenv(t_env *init)
{
	t_dist	*dist;

	if (!(dist = (t_dist *)malloc(sizeof(*dist))))
		error("error : Malloc dist");
	init->width = 1280;
	init->height = 800;
	init->center = init->height / 2;
	init->posinitx = -1;
	init->posinity = -1;
	init->camangle = 90;
	init->camy = 0;
	init->dist = dist;
	init->dist->distval = 0;
	init->dist->color = 0;
	init->img = ft_init_img(init);
}

void			mlx_var(t_env *init, char **av)
{
	init->mlx = mlx_init();
	ft_initenv(init);
	init->point = ft_createstruct(init, av);
	init->win = mlx_new_window(init->mlx, init->width, init->height,
	"WOLF3D");
	raycaster(init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	mlx_hook(init->win, 2, 0, key_hook, init);
	mlx_hook(init->win, 6, 0, mousecam, init);
	mlx_expose_hook(init->win, expose_hook, init);
	mlx_loop(init->mlx);
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac == 2)
	{
		if (!(init = (t_env *)malloc(sizeof(*init))))
			error("error : main");
		mlx_var(init, av);
	}
	else
		error("error : ac != 2");
	return (0);
}
