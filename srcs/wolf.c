/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/23 15:59:28 by amoinier         ###   ########.fr       */
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
	init->width = 1280;
	init->height = 800;
	init->posinitx = -1;
	init->posinity = -1;
	init->sizeb = 64;
	init->sizefps = init->sizeb / 2;
	init->angle = 60;
	init->poscamx = 0;
	init->poscamy = 0;
	init->camangle = 0;
	init->moveh = 0;
	init->moved = 0;
	init->img = ft_init_img(init);
}

void			mlx_var(t_env *init, char **av)
{
	init->mlx = mlx_init();
	ft_initenv(init);
	init->point = ft_createstruct(init, av);
	init->win = mlx_new_window(init->mlx, init->width, init->height,
	"WOLF3D");
	raycaster(init, init->point);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	mlx_hook(init->win, 2, 0, key_hook, init);
	//mlx_hook(init->win, 6, 0, mouse, init);
	//mlx_hook(init->win, 4, 0, mouse_hook, init);
	//mlx_expose_hook(init->win, expose_hook, init);
	mlx_loop(init->mlx);
}

int				main(int ac, char **av)
{
	t_env	*init;

	(void)av;
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
