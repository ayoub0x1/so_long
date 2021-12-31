/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:30:44 by roudouch          #+#    #+#             */
/*   Updated: 2021/12/14 13:30:45 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_vars ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_vars **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./img/wall.xpm");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./img/floor.xpm");
		put_image(&v, x1, y1, "./img/collect.xpm");
		(*v)->collect++;
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./img/exit.xpm");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		put_image(&v, x1, y1, "./img/floor.xpm");
		put_image(&v, x1, y1, "./img/front.xpm");
	}
	else
		put_image(&v, x1, y1, "./img/floor.xpm");
}
