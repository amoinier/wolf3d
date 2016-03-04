/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/04 20:00:41 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	t_point		***ft_realloc(t_point ***p, int nline)
{
	t_point	***tmp;
	int		i;

	i = 0;
	if (!(tmp = (t_point ***)malloc(sizeof(tmp) * (nline + 1))))
		error("error : ft_realloc");
	while (i != nline)
	{
		tmp[i] = p[i];
		i++;
	}
	free(p);
	p = NULL;
	p = tmp;
	return (p);
}

t_point				***ft_createstruct(t_env *init, char **av)
{
	t_point	***point;
	int		fd;
	int		i;
	int		ret;
	char	*line;

	i = 0;
	if (!(point = (t_point ***)malloc(sizeof(point))))
		error("error : ft_createstruct");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("error : Bad fd");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		point[i] = init_point(init, line, i);
		point = ft_realloc(point, i + 1);
		free(line);
		i++;
	}
	close(fd);
	if (ret != 0 || i == 0)
		error("error : ret != 0 || i == 0");
	free(line);
	line = NULL;
	point[0][0]->sizeline = i;
	return (point);
}
