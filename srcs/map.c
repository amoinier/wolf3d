/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 18:30:27 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/11 16:22:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static	void	drawbox(t_env *init, int x, int y, int color)
{
	int	j;
	int	i;

	j = y - 4;
	while (j <= y + 4)
	{
		i = x - 4;
		while (i <= x + 4)
		{
			pixel_put_map(init, i, j, color);
			i++;
		}
		j++;
	}
}

static	void	drawboxfps(t_env *init, int x, int y, int color)
{
	int	j;
	int	i;

	j = y - 1;
	while (j <= y + 1)
	{
		i = x - 1;
		while (i <= x + 1)
		{
			pixel_put_map(init, i, j, color);
			i++;
		}
		j++;
	}
}

void			drawmap(t_env *init)
{
	int	y;
	int	x;

	y = 0;
	while (y < init->point[0][0]->sizeline)
	{
		x = 0;
		while (x < init->point[y][0]->sizecol)
		{
			if (init->point[y][x]->z == 1)
				drawbox(init, 4 + x * 7, 4 + y * 7, 0xffffff);
			x++;
		}
		y++;
	}
	drawboxfps(init, 1 + init->posinitx * 7, 1 + init->posinity * 7, 0xff3b3b);
}
