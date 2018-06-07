/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octan_part_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:29:06 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/30 14:37:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_octan_six(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->y1 = val->y1 - 1) == val->y2)
			break ;
		if ((val->e = val->e - val->dx) >= 0)
		{
			--val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_seven(t_shape *shape, t_draw *val, int col)
{
	val->e = val->dy;
	val->dx *= 2;
	val->dy *= 2;
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->y1 = val->y1 - 1) == val->y2)
			break ;
		if ((val->e = val->e + val->dx) > 0)
		{
			++val->x1;
			val->e += val->dy;
		}
	}
}

void		draw_octan_eight(t_shape *shape, t_draw *val, int col)
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
		if ((val->e = val->e + val->dy) < 0)
		{
			--val->y1;
			val->e += val->dx;
		}
	}
}

void		draw_horizontal_right(t_shape *shape, t_draw *val, int col)
{
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->x1 = val->x1 + 1) == val->x2)
			break ;
	}
}

void		draw_horizontal_left(t_shape *shape, t_draw *val, int col)
{
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->x1 = val->x1 - 1) == val->x2)
			break ;
	}
}
