/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:52:41 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/13 09:07:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_line_len(char *line)
{
	int		line_len;
	char	**tmp;

	tmp = ft_split_whitespaces(line);
	line_len = 0;
	while (tmp[line_len])
		++line_len;
	ft_clear_tmp(tmp);
	return (line_len);
}

void		ft_check_stock(int fd, t_shape *shape)
{
	char	*line;
	int		y;

	shape->current = ((t_slist *)shape->list);
	if (get_next_line(fd, &line) <= 0)
		ft_error("error: Not valid file", 1);
	shape->line_len = ft_check_line_len(line);
	shape->previous = ft_add_first_line(shape, line, 0);
	ft_memdel((void **)&line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line_len(line) != shape->line_len)
			ft_error("error: Wrong line length", 2);
		if (!(((t_slist *)shape->current)->next_y =
		(t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(((t_slist *)shape->current)->next_y->link =
		(t_link *)ft_memalloc(sizeof(t_link))))
			return ;
		shape->current = ((t_slist *)shape->current)->next_y;
		shape->previous = ft_add_next_line(shape, line, ++y);
		ft_memdel((void **)&line);
	}
	shape->y_max = y;
	ft_memdel((void **)&line);
}
