/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:10:31 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/03 14:59:51 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <mlx.h>

#define PI 3.14159265

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;

	int			px;
	int			py;

	int			sizeline;
	int			sizecol;
	int			col;
}				t_point;

typedef	struct	s_img
{
	void		*img;
	char		*cimg;
	int			width;
	int			height;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	int			sizeb;
	int			sizefps;
	double		posinitx;
	double		posinity;
	int			poscamx;
	int			poscamy;
	int			camangle;
	double		distval;

	t_img		*img;
	t_img		*sky;
	t_point		***point;
}				t_env;

int				mouse_hook(int button, int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				expose_hook(t_env *init);

void			mlx_var(t_env *init, char **av);

void			raycaster(t_env *init);
double				adn(t_env *init, double x1, double x2, double y1, double y2);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			print_xpm(t_env *init, char *filename);
void			ft_clear_img(t_env *init);

int				ft_countcara(char *str);
t_point			***ft_createstruct(t_env *init, char **av);
t_point			**init_point(t_env *init, char *line, int j);

int				error(char *s);

#endif
