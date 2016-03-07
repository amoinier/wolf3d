/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:09:53 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/07 17:35:40 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	t_img	*ft_init_img(t_env *init, int w, int h)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error("error : ft_init_img");
	img->img = mlx_new_image(init->mlx, w, h);
	img->bpp = 0;
	img->sizel = 0;
	img->endn = 0;
	img->cimg = mlx_get_data_addr(img->img, &img->bpp, &img->sizel, &img->endn);
	return (img);
}

static	void	ft_initenv(t_env *init, char *av)
{
	t_dist	*dist;

	if (!(dist = (t_dist *)malloc(sizeof(*dist))))
		error("error : Malloc dist");
	init->games = 1;
	init->width = 1280;
	init->height = 800;
	init->center = init->height / 2;
	init->mapkey = 0;
	init->posinitx = -1;
	init->posinity = -1;
	init->scale = 60 / (double)init->width;
	init->camangle = 315;
	init->camy = 0;
	init->run = 15;
	init->activey = 0;
	init->dist = dist;
	init->dist->distval = 0;
	init->dist->color = 0;
	init->name = av;
	init->point = ft_createstruct(init, av);
	if (init->posinitx == -1 || init->posinity == -1)
		error("error : posinitx == -1");
	init->posinity += 0.5;
	init->posinitx += 0.5;
	init->map = ft_init_img(init, 500, 500);
	init->img = ft_init_img(init, init->width, init->height);
}

void			mlx_var(t_env *init, char *av)
{
	static	int	x = 0;

	if (x == 0)
		init->mlx = mlx_init();
	x++;
	init->win = mlx_new_window(init->mlx, 1280, 800,
	"WOLF3D");
	ft_initenv(init, av);
	mlx_hook(init->win, 6, 0, mousecam, init);
	mlx_hook(init->win, 2, 1, key_hook, init);
	if (ft_strequ(init->name, "map/end"))
	{
		init->games = 0;
		mlx_string_put(init->mlx, init->win, init->width / 2 - 150,
		init->height / 2, 0xffffff, "Vous avez finis le jeux !");
		mlx_string_put(init->mlx, init->win, init->width / 2 - 150,
		init->height / 2 + 20, 0xff0000, "Appuyez sur [ESC] pour quitter");
	}
	mlx_expose_hook(init->win, expose_hook, init);
	mlx_loop(init->mlx);
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac <= 2)
	{
		if (!(init = (t_env *)malloc(sizeof(*init))))
			error("error : main");
		if (ac == 1)
			mlx_var(init, selectmaps());
		else
			mlx_var(init, av[1]);
	}
	else
		error("error : ac > 2");
	return (0);
}
