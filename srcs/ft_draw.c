/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:04:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/20 12:47:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_funct(t_shape *shape)
{
	t_slist		*i;
	t_slist		*j;

	i = shape->list;
	while (i)
	{
		j = i;
		while (j)
		{
			choose_color(shape, j);
			j = j->next_x;
		}
		i = i->next_y;
	}
}

static void		ft_draw_funct_end(t_shape *shape)
{
	t_slist		*i;
	t_slist		*j;

	i = shape->end_list;
	while (i)
	{
		j = i;
		while (j)
		{
			choose_color(shape, j);
			j = j->prev_x;
		}
		i = i->prev_y;
	}
}

static void		ft_xtrem_values(t_shape *shape, t_link *ptr)
{
	if (!shape->max_y || *shape->max_y < (int)ptr->v)
		*shape->max_y = (int)ptr->v;
	if (!shape->max_x || *shape->max_x < (int)ptr->u)
		*shape->max_x = (int)ptr->u;
	if (!shape->min_y || *shape->min_y > (int)ptr->v)
		*shape->min_y = (int)ptr->v;
	if (!shape->min_x || *shape->min_x > (int)ptr->u)
		*shape->min_x = (int)ptr->u;
}

void			ft_projection(t_shape *shape)
{
	t_slist		*i;
	t_slist		*j;
	t_link		*ptr;

	i = shape->list;
	while (i)
	{
		j = i;
		while (j)
		{
			ptr = (t_link *)j->link;
			projection_calcul(shape, ptr);
			if (shape->first == 0)
				ft_xtrem_values(shape, ptr);
			j = j->next_x;
		}
		i = i->next_y;
	}
	shape->first = 1;
	if (shape->rot > (46.0 * M_PI / 180.0)
			&& shape->rot < (225.0 * M_PI / 180.0))
		ft_draw_funct_end(shape);
	else
		ft_draw_funct(shape);
}

void			ft_draw(t_shape *shape)
{
	shape->mlx = mlx_init();
	shape->win_x = 800;
	shape->win_y = 600;
	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->agr = 0.2;
	shape->alpha = 1.0;
	shape->win = mlx_new_window(shape->mlx, shape->win_x, shape->win_y, "fdf");
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	shape->start_x = (*shape->min_x - (shape->win_x / 2));
	shape->start_y = (*shape->max_y + (shape->img_y / 2));
	shape->speed = 10;
	shape->rot = 0.0 * M_PI / 180;
	shape->coef_x = 0.0 * M_PI / 180;
	shape->coef_y = 120.0 * M_PI / 180;
	shape->coef_z = 120.0 * M_PI / 180;
	shape->coef_a = 30.0 * M_PI / 180;
	ft_projection(shape);
	ft_start_auto_funct(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	mlx_hook(shape->win, 2, (1L << 0), ft_key_funct, shape);
	mlx_mouse_hook(shape->win, ft_mouse_funct, shape);
	mlx_loop(shape->mlx);
}
