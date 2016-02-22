/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 19:10:31 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/22 18:39:35 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <mlx.h>

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

	t_img		*img;
	t_point		***point;

	int			movex;
	int			movey;
	float		axex;
	float		axey;
	int			axez;
	int			zoom;
	char		*lol;
	int			col;
}				t_env;

int				mouse_hook(int button, int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				expose_hook(t_env *init);

void			mlx_var(t_env *init, char **av);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			ft_clear_img(t_env *init);

int				ft_countcara(char *str);
t_point			***ft_createstruct(char **av);
t_point			**init_point(char *line, int j);

int				error(void);

#endif
