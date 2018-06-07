/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:35:37 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/05 15:25:28 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
{
	(void)x;
	(void)y;
	if (mouse == MWHEELDOWN || mouse == MWHEELUP)
	{
		mlx_clear_window(shape->mlx, shape->win);
		mlx_destroy_image(shape->mlx, shape->img);
		shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
		shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
				&shape->sizeline, &shape->endian);
		if (mouse == MWHEELDOWN)
		{
			shape->agr *= 1.1;
			shape->speed += 2;
		}
		if (mouse == MWHEELUP)
		{
			shape->agr /= 1.1;
			shape->speed -= 2;
		}
		ft_projection(shape);
		mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	}
	return (0);
}

static void		ft_rotate(int key, t_shape *shape)
{
	if (key == KEY_D)
	{
		if (shape->rot < 350.0 * M_PI / 180.0)
			shape->rot += 10.0 * M_PI / 180.0;
		else
			shape->rot = 0.0 * M_PI / 180.0;
	}
	if (key == KEY_A)
	{
		if (shape->rot > 0.0 * M_PI / 180.0)
			shape->rot -= 10.0 * M_PI / 180.0;
		else
			shape->rot = 350.0 * M_PI / 180.0;
	}
}

static void		move_others(int key, t_shape *shape)
{
	if (key == EQUAL)
		shape->agr *= 1.1;
	if (key == MINUS)
		shape->agr /= 1.1;
	if (key == R_ARROW)
		shape->start_x += shape->speed;
	if (key == L_ARROW)
		shape->start_x -= shape->speed;
	if (key == D_ARROW)
		shape->start_y -= shape->speed;
	if (key == U_ARROW)
		shape->start_y += shape->speed;
	if (key == SPACE)
	{
		shape->rot = 0.0 * M_PI / 180.0;
		shape->coef_x = 0.0 * M_PI / 180.0;
		shape->coef_y = 120.0 * M_PI / 180.0;
		shape->coef_z = 120.0 * M_PI / 180.0;
		shape->coef_a = 30.0 * M_PI / 180.0;
	}
}

static void		ft_auto_funct(int key, t_shape *shape)
{
	if (key == ENTER)
	{
		if (shape->ok_rotate != 1)
			shape->ok_rotate = 1;
		else
			shape->ok_rotate = 0;
	}
	if (key == R_SHIFT)
	{
		if (shape->ok_z != 1)
			shape->ok_z = 1;
		else
			shape->ok_z = 0;
	}
}

int				ft_key_funct(int key, t_shape *shape)
{
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	if (key == KEY_A || key == KEY_D)
		ft_rotate(key, shape);
	if (key == EQUAL || key == MINUS || key == SPACE
			|| (key >= L_ARROW && key <= U_ARROW))
		move_others(key, shape);
	if (key == ESC)
	{
		ft_clear_list(&shape->list);
		exit(0);
	}
	if (key == ENTER || key == R_SHIFT)
		ft_auto_funct(key, shape);
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}
