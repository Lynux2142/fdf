/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:22:30 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/19 10:39:38 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_rotate_auto(t_shape *shape)
{
	if (shape->ok_rotate == 1)
	{
		mlx_clear_window(shape->mlx, shape->win);
		mlx_destroy_image(shape->mlx, shape->img);
		shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
		shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
				&shape->sizeline, &shape->endian);
		if (shape->rot <= 360.0 * M_PI / 180.0)
			shape->rot += 1.0 * M_PI / 180.0;
		else
			shape->rot = 1.0 * M_PI / 180.0;
		ft_projection(shape);
		mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	}
	return (0);
}

int		ft_change_z(int x, int y, t_shape *shape)
{
	(void)x;
	if (shape->ok_z == 1)
	{
		mlx_clear_window(shape->mlx, shape->win);
		mlx_destroy_image(shape->mlx, shape->img);
		shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
		shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
				&shape->sizeline, &shape->endian);
		shape->alpha = -((double)y / shape->win_x * 10 - 4);
		ft_projection(shape);
		mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	}
	return (0);
}

void	ft_start_auto_funct(t_shape *shape)
{
	mlx_loop_hook(shape->mlx, ft_rotate_auto, shape);
	mlx_hook(shape->win, 6, (1L << 6), ft_change_z, shape);
}
