/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:47:21 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/15 16:48:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**static void		ft_print_list(t_slist *list)
**{
**	t_slist		*line;
**	char		*nbr;
**
**	while (list)
**	{
**		line = list;
**		while (line)
**		{
**			ft_putnbr(((t_link *)line->link)->z);
**			if (((t_link *)line->link)->color)
**			{
**				ft_putstr(",0x");
**				nbr = ft_itoa_base(((t_link *)line->link)->color, 16);
**				ft_putstr(nbr);
**				ft_memdel((void **)&nbr);
**			}
**			if (line->next_x != NULL)
**				ft_putchar(' ');
**			line = line->next_x;
**		}
**		ft_putchar('\n');
**		list = list->next_y;
**	}
**}
*/

int				main(int ac, char **av)
{
	t_shape	shape;
	int		fd;

	if (ac != 2)
		ft_error("usage: ./fdf [file_name.fdf]", 4);
	if (!(shape.max_y = (int *)ft_memalloc(sizeof(int)))
	|| !(shape.max_x = (int *)ft_memalloc(sizeof(int)))
	|| !(shape.min_y = (int *)ft_memalloc(sizeof(int)))
	|| !(shape.min_x = (int *)ft_memalloc(sizeof(int)))
	|| ((fd = open(av[1], O_RDONLY)) == -1)
	|| !(shape.list = (t_slist *)ft_memalloc(sizeof(t_slist)))
	|| !(((t_slist *)shape.list)->link =
		(t_link *)ft_memalloc(sizeof(t_link))))
	{
		perror("error");
		return (-1);
	}
	((t_link *)((t_slist *)shape.list)->link)->x = 0;
	((t_link *)((t_slist *)shape.list)->link)->y = 0;
	ft_check_stock(fd, &shape);
	ft_draw(&shape);
	ft_clear_list(&shape.list);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
