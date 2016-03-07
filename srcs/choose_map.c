/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:41:27 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/07 17:31:13 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*selectmaps(void)
{
	char		*maps[10];
	static	int	x = -1;

	x++;
	maps[0] = "map/wall";
	maps[1] = "map/test";
	maps[2] = "map/try";
	maps[3] = "map/1";
	maps[4] = "map/level1";
	maps[5] = "map/acc";
	maps[6] = "map/level2";
	maps[7] = "map/oc";
	maps[8] = "map/lab1";
	maps[9] = "map/end";
	return (maps[x]);
}
