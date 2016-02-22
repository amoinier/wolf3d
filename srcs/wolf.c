/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/22 18:39:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	t_img	*ft_init_img(t_env *init)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error();
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
	init->height = 720;
	init->movex = 0;
	init->movey = 0;
	init->axex = 0;
	init->axey = 0;
	init->axez = 2;
	init->zoom = 4;
	init->col = 0;
	init->img = ft_init_img(init);
}

void			mlx_var(t_env *init, char **av)
{
	init->point = ft_createstruct(av);
	init->mlx = mlx_init();
	ft_initenv(init);
	init->win = mlx_new_window(init->mlx, init->width, init->height,
	"WOLF3D");
	init->lol = av[1];
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
			error();
		mlx_var(init, av);
	}
	return (0);
}
