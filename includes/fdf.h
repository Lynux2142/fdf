/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:33:17 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/05 16:29:28 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifdef __linux__
#  define ESC			65307
#  define U_ARROW		65362
#  define D_ARROW		65364
#  define R_ARROW		65363
#  define L_ARROW		65361
#  define KEY_A			97
#  define KEY_D			100
#  define SPACE			32
#  define EQUAL			61
#  define MINUS			45
#  define ENTER			65293
#  define R_SHIFT		65506
#  define L_CLIC		1
#  define R_CLIC		3
#  define MID_CLIC		2
#  define MWHEELUP		4
#  define MWHEELDOWN	5
# else
#  define ESC			53
#  define U_ARROW		126
#  define D_ARROW		125
#  define R_ARROW		124
#  define L_ARROW		123
#  define KEY_A			0
#  define KEY_D			2
#  define SPACE			49
#  define EQUAL			24
#  define MINUS			27
#  define ENTER			36
#  define R_SHIFT		258
#  define L_CLIC		1
#  define R_CLIC		2
#  define MID_CLIC		3
#  define MWHEELUP		4
#  define MWHEELDOWN	5
# endif

typedef struct				s_shape
{
	int						first;
	struct s_slist			*list;
	struct s_slist			*end_list;
	struct s_slist			*previous;
	struct s_slist			*current;
	struct s_slist			*temp;
	struct s_slist			*prev_y;
	struct s_slist			*prev_x;
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						bpp;
	int						sizeline;
	int						endian;
	int						*min_y;
	int						*max_y;
	int						*min_x;
	int						*max_x;
	double					agr;
	int						width;
	int						win_x;
	int						win_y;
	int						img_x;
	int						img_y;
	double					coef_x;
	double					coef_y;
	double					coef_z;
	double					coef_a;
	double					rot;
	int						start_x;
	int						start_y;
	int						speed;
	int						x_max;
	int						y_max;
	char					**tmp;
	int						line_len;
	char					ok_rotate;
	char					ok_z;
	double					alpha;
}							t_shape;

typedef struct				s_slist
{
	struct s_slist			*next_x;
	struct s_slist			*next_y;
	struct s_slist			*prev_x;
	struct s_slist			*prev_y;
	struct s_link			*link;
}							t_slist;

typedef struct				s_link
{
	int						x;
	int						y;
	int						z;
	char					*color;
	double					u;
	double					v;
}							t_link;

typedef struct				s_draw
{
	int						x1;
	int						y1;
	int						x2;
	int						y2;
	int						dy;
	int						dx;
	int						e;
}							t_draw;

void						ft_check_stock(int fd, t_shape *shape);
void						ft_clear_list(t_slist **list);
t_slist						*ft_add_first_line(t_shape *shape,
		char *line, int y);
t_slist						*ft_add_next_line(t_shape *shape,
		char *line, int y);
void						ft_draw(t_shape *shape);
int							ft_couleur(int red, int green, int blue);
void						ft_projection(t_shape *shape);
int							ft_mouse_funct(int mouse, int x, int y,
		t_shape *shape);
int							ft_key_funct(int key, t_shape *shape);
int							ft_couleur(int red, int green, int blue);
void						fill_pixel(t_shape *shape, int x, int y, int color);
void						projection_calcul(t_shape *shape, t_link *ptr);
void						ft_draw_segment(t_shape *shape,
		t_link *xy1, t_link *xy2, int col);
void						draw_octan_one(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_two(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_three(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_four(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_five(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_six(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_seven(t_shape *shape,
		t_draw *val, int col);
void						draw_octan_eight(t_shape *shape,
		t_draw *val, int col);
void						draw_horizontal_right(t_shape *shape,
		t_draw *val, int col);
void						draw_horizontal_left(t_shape *shape,
		t_draw *val, int col);
void						draw_vertical_increasing(t_shape *shape,
		t_draw *val, int col);
void						draw_vertical_decreasing(t_shape *shape,
		t_draw *val, int col);
void						ft_clear_tmp(char **tmp);
int							ft_rotate_auto(t_shape *shape);
void						choose_color(t_shape *shape, t_slist *list);
int							ft_change_z(int x, int y, t_shape *shape);
void						ft_start_auto_funct(t_shape *shape);

#endif
