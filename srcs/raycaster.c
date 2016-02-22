/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/22 20:19:53 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    raycaster(t_env *init, t_point ***point)
{
  int x;
  int y;

  y = 0;
  //ft_putnbr(point[0][0]->sizecol);
  while (y < point[0][0]->sizeline)
  {
    x = 0;
    while (x < point[y][0]->sizecol)
    {
      point[y][x]->px = 30 + x * init->sizeb;
      point[y][x]->py = 30 + y * init->sizeb;
      if (point[y][x]->z == 42)
        pixel_put_image(init, point[y][x]->px, point[y][x]->py, 0xff0000);
      else
        pixel_put_image(init, point[y][x]->px, point[y][x]->py, 0xffffff);
      x++;
    }
    y++;
  }
}
