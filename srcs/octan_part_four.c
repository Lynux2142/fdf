/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octan_part_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:31:54 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/30 14:47:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_vertical_increasing(t_shape *shape, t_draw *val, int col)
{
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->y1 = val->y1 + 1) == val->y2)
			break ;
	}
}

void		draw_vertical_decreasing(t_shape *shape, t_draw *val, int col)
{
	while (1)
	{
		fill_pixel(shape, val->x1 - shape->start_x,
				val->y1 + shape->start_y, col);
		if ((val->y1 = val->y1 - 1) == val->y2)
			break ;
	}
}
