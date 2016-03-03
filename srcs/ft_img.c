/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:13:16 by amoinier          #+#    #+#             */
/*   Updated: 2016/03/03 15:04:53 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			ft_clear_img(t_env *init)
{
	int	size;

	size = init->width * init->height * 4 - 1;
	ft_bzero(init->img->cimg, size);
}

void			pixel_put_image(t_env *init, int x, int y, int color)
{
	int		i;
	int		bpp;
	int		sizeline;
	char	*data;

	bpp = init->img->bpp;
	sizeline = init->img->sizel;
	data = init->img->cimg;
	if (x < init->width && y < init->height && x > 0 && y > 0)
	{
		i = x * (bpp / 8) + y * sizeline;
		data[i] = color % 256;
		color /= 256;
		data[i + 1] = color % 256;
		color /= 256;
		data[i + 2] = color % 256;
	}
}

void	print_xpm(t_env *init, char *filename)
{
	init->sky->height = 200;
	init->sky->width = 200;
	init->sky = mlx_xpm_file_to_image(init->mlx, filename, &init->sky->width, &init->sky->height);
	mlx_put_image_to_window(init->mlx, init->win, init->sky, 0, 0);
}
