/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:10:31 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/11 13:57:35 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <mlx.h>
# include <time.h>

# define RAD 0.0174532925
# define PI 3.14159265359

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			sizeline;
	int			sizecol;
}				t_point;

typedef	struct	s_img
{
	void		*img;
	char		*cimg;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

typedef	struct	s_dist
{
	double		distval;
	int			color;
}				t_dist;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			center;
	int			mapkey;
	int			run;
	int			activey;
	int			games;

	time_t		start_time;

	char		*name;

	double		scale;
	double		posinitx;
	double		posinity;
	double		camy;
	int			camangle;

	t_img		*img;
	t_img		*map;
	t_point		***point;
	t_dist		*dist;

}				t_env;

int				mouse_hook(int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				loop_hook(t_env *init);
int				expose_hook(t_env *init);

void			move(int keycode, t_env *init);
void			load_map(t_env *init);

void			mlx_var(t_env *init, char *av);

void			drawmap(t_env *init);
void			raycaster(t_env *init);
double			adn(t_env *init, double xy2[2]);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			pixel_put_map(t_env *init, int x, int y, int color);
void			ft_clear_img(t_env *init);

int				ft_countcara(char *str);
t_point			***ft_createstruct(t_env *init, char *av);
t_point			**init_point(t_env *init, char *line, int j);
void			verif_map(t_point ***point);

void			utils(t_env *init, int keycode, double sa, double ca);

int				error(char *s);

char			*selectmaps(void);

#endif
