/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:42:35 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/22 20:18:59 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	t_point		*ft_pointnew(int x, int y, int z, int coln)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		error("error : ft_pointnew");
	point->x = x;
	point->y = y;
	point->z = z;
	point->px = 0;
	point->py = 0;
	point->sizeline = 0;
	if (x == 0)
		point->sizecol = coln;
	point->col = 0;
	return (point);
}

static	int			verif_str(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}

t_point				**init_point(t_env *init, char *line, int j)
{
	int		i;
	int		coln;
	char	**s;
	t_point	**point;

	i = 0;
	coln = ft_countcara(line);
	s = ft_strsplit(line, 32);
	if (!(point = (t_point **)malloc(sizeof(*point) * (coln + 1))))
		error("error : init_point");
	while (i < coln)
	{
		if (verif_str(s[i]) == 0)
			error("error : verif_str");
		point[i] = ft_pointnew(i, j, ft_atoi(s[i]), coln);
		if (point[i]->z == 42)
		{
			init->posinitx = i;
			init->posinity = j;
		}
		free(s[i]);
		i++;
	}
	if (i == 0)
		error("error : i == 0");
	free(s);
	return (point);
}
