/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/16 14:56:00 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_clear_tmp(char **tmp)
{
	int i;

	i = -1;
	while (tmp[++i])
		ft_memdel((void **)&tmp[i]);
	ft_memdel((void **)&tmp);
}

static void		ft_register(t_shape *shape, int x, int y, char *z_col)
{
	t_link	*data;
	char	**tmp;
	char	*test_overflow;

	data = shape->temp->link;
	tmp = ft_strsplit(z_col, ',');
	data->x = x;
	data->y = y;
	if (!tmp)
		ft_error("error: Not valid file", 3);
	if (!ft_strequ((test_overflow = ft_itoa(ft_atoi(tmp[0]))), tmp[0]))
	{
		ft_memdel((void **)&test_overflow);
		ft_error("error: Overflow", 5);
	}
	ft_memdel((void **)&test_overflow);
	data->z = ft_atoi(tmp[0]);
	if (tmp[1])
		if (!(data->color = (char *)malloc(sizeof(char) * ft_strlen(tmp[1]))))
			exit(8);
	data->color = (tmp[1]) ? ft_strcpy(data->color, tmp[1]) : NULL;
	ft_clear_tmp(tmp);
}

void			ft_clear_list(t_slist **list)
{
	t_slist	*current;
	t_slist	*next_line;
	t_slist	*tmp;

	next_line = *list;
	while (next_line)
	{
		current = next_line;
		next_line = next_line->next_y;
		while (current)
		{
			tmp = current;
			current = current->next_x;
			ft_memdel((void **)&tmp->link);
			ft_memdel((void **)&tmp);
		}
	}
}

t_slist			*ft_add_first_line(t_shape *shape, char *line, int y)
{
	char		**tmp;
	int			x;

	x = 0;
	shape->temp = ((t_slist *)shape->current);
	tmp = ft_split_whitespaces(line);
	shape->width = 0;
	ft_register(shape, shape->width, y, tmp[shape->width]);
	while (tmp[++shape->width])
	{
		if (!(shape->temp->next_x = (t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(shape->temp->next_x->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return (NULL);
		shape->temp->next_x->prev_x = shape->temp;
		shape->temp = shape->temp->next_x;
		ft_register(shape, shape->width, y, tmp[shape->width]);
		++x;
	}
	shape->x_max = x;
	ft_clear_tmp(tmp);
	return (shape->list);
}

t_slist			*ft_add_next_line(t_shape *shape, char *line, int y)
{
	int			x;

	shape->temp = ((t_slist *)shape->current);
	shape->tmp = ft_split_whitespaces(line);
	x = 0;
	ft_register(shape, x, y, shape->tmp[x]);
	while (shape->tmp[++x])
	{
		if (!(shape->temp->next_x = (t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(shape->temp->next_x->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return (NULL);
		shape->temp->next_x->prev_x = shape->temp;
		shape->temp->prev_y = shape->previous;
		shape->previous->next_y = shape->temp;
		shape->temp = shape->temp->next_x;
		shape->previous = shape->previous->next_x;
		ft_register(shape, x, y, shape->tmp[x]);
	}
	shape->temp->prev_y = shape->previous;
	shape->previous->next_y = shape->temp;
	shape->end_list = shape->temp;
	ft_clear_tmp(shape->tmp);
	return (shape->current);
}
