/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:37:32 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/24 11:24:35 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int   dist_cam(t_point ***point, int xcam, int ycam)
{
    int y;

    y = ycam;
    while (y >= 0)
    {
        if (point[y][xcam]->z == 1)
            return (y);
        y--;
    }
    return (-1);
}

void    draw_sky(t_env *init, int x, int sizewall)
{
    int     y;

    y = 0;
    while (y <= (init->height / 2) - (sizewall / 2))
    {
        pixel_put_image(init, x, y, 0x1272af);
        y++;
    }
}

void    draw_wall(t_env *init, int x, int sizewall)
{
    int     y;

    y = (init->height / 2) - (sizewall / 2);
    while (y <= (init->height / 2) + (sizewall / 2))
    {
        pixel_put_image(init, x, y, 0x5b0202);
        y++;
    }
}

void    draw_floor(t_env *init, int x, int sizewall)
{
    int     y;

    y = (init->height / 2) + (sizewall / 2);
    while (y <= init->height)
    {
        pixel_put_image(init, x, y, 0x373737);
        y++;
    }
}

void    raycaster(t_env *init, t_point ***point)
{
    int x;
    int sizewall;
    int dist;

    x = 0;
    dist = init->posinity - (dist_cam(point, init->posinitx, init->posinity));
    if (dist <= 0)
        dist = 1;
    sizewall = init->height / dist;
    while (x <= init->width)
    {
        draw_sky(init, x, sizewall);
        draw_wall(init, x, sizewall);
        draw_floor(init, x, sizewall);
        x++;
    }
}
