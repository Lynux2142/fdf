/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octan_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:40:51 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/31 15:41:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_dx_positive(t_shape *shape, t_draw *val, int col)
{
	if (val->dy > 0)
	{
		if (val->dx >= val->dy)
			draw_octan_one(shape, val, col);
		else
			draw_octan_two(shape, val, col);
	}
	else if (val->dy < 0)
	{
		if (val->dx >= (-val->dy))
			draw_octan_eight(shape, val, col);
		else
			draw_octan_seven(shape, val, col);
	}
	else
		draw_horizontal_right(shape, val, col);
}

static void		ft_dx_negative(t_shape *shape, t_draw *val, int col)
{
	if (val->dy > 0)
	{
		if ((-val->dx) >= val->dy)
			draw_octan_four(shape, val, col);
		else
			draw_octan_three(shape, val, col);
	}
	else if (val->dy < 0)
	{
		if (val->dx <= val->dy)
			draw_octan_five(shape, val, col);
		else
			draw_octan_six(shape, val, col);
	}
	else
		draw_horizontal_left(shape, val, col);
}

void			ft_draw_segment(t_shape *shape, t_link *xy1,
				t_link *xy2, int col)
{
	t_draw	val;

	val.x1 = xy1->u;
	val.y1 = xy1->v;
	val.x2 = xy2->u;
	val.y2 = xy2->v;
	val.dx = val.x2 - val.x1;
	val.dy = val.y2 - val.y1;
	if (val.dx > 0)
		ft_dx_positive(shape, &val, col);
	else if (val.dx < 0)
		ft_dx_negative(shape, &val, col);
	else
	{
		if (val.dy > 0)
			draw_vertical_increasing(shape, &val, col);
		else if (val.dy < 0)
			draw_vertical_decreasing(shape, &val, col);
	}
	fill_pixel(shape, val.x2 - shape->start_x,
			val.y2 + shape->start_y, col);
}
