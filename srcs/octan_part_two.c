/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octan_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:42:34 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/30 14:35:42 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_octan_one(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->x1 = val->x1 + 1) == val->x2)
			break ;
		if ((val->e = val->e - val->dy) < 0)
		{
			++val->y1;
			val->e += val->dx;
		}
	}
}

void		draw_octan_two(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->y1 = val->y1 + 1) == val->y2)
			break ;
		if ((val->e = val->e - val->dx) < 0)
		{
			++val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_three(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->y1 = val->y1 + 1) == val->y2)
			break ;
		if ((val->e = val->e + val->dx) <= 0)
		{
			--val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_four(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->x1 = val->x1 - 1) == val->x2)
			break ;
		if ((val->e = val->e + val->dy) >= 0)
		{
			++val->y1;
			val->e += val->dx;
		}
	}
}

void		draw_octan_five(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dx;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->x1 = val->x1 - 1) == val->x2)
			break ;
		if ((val->e = val->e - val->dy) >= 0)
		{
			--val->y1;
			val->e += val->dx;
		}
	}
}
