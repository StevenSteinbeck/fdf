/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 08:31:27 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 18:05:34 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W	1440
# define WIN_H	900
#include <stdlib.h>

typedef struct	s_vert
{
	char		*str;
	double		x;
	double		y;
	double		z;
	double		w;
	int			*index;
	int			color;
}				t_vert;

typedef struct	s_map
{
	int			array;
	int			width;
	int			height;
	int			max_z;
	int			min_z;
	char		*ptr;
	int			zbuf[WIN_H * WIN_W];
	t_vert		*verts;
	t_vert		*xverts;
	size_t		*map_x;
}				t_map;

typedef struct	s_trmat
{
	char		ret;
	int			rows;
	int			cols;
	double		m[16];
	char		str[32];
}				t_trmat;

typedef struct	s_image
{
	int			i_file;
	void		*image;
	char		*ptr;
	size_t		place;
	int			bpp;
	int			line_s;
	int			line;
	int			endian;
}				t_image;

typedef struct	s_mouse
{
	int			count;
	double		prev_x;
	double		prev_y;
	double		saved_y;
	double		x;
	double		y;
	int			is_pressed;
	char		*str;
}				t_mouse;

typedef struct	s_envars
{
	void		*mlx;
	int			ret;
	void		*win;
	int			fd;
	t_image		image;
	t_map		map;
	t_mouse		mouse;
	char		shift;
	double		x_shift;
	double		y_shift;
	double		z_shift;
	double		x_rot;
	double		y_rot;
	double		z_rot;
	double		x_sca;
	double		y_sca;
	double		z_sca;
	double		indx;
	int			c_min;
	int			c_max;
	int			color_style;
	int			point_mode;
	int			no_zbuf_mode;
}				t_envars;

void	put_info(t_envars *env);

typedef struct	s_line
{
	int			x0;
	int			x0cpy;
	int			y0;
	int			y0cpy;
	int			x1;
	int			x1cpy;
	int			y1;
	int			x2cpy;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			err2;
	int			err3;
	int			color;
	double		dec_pcnt;
	char		*error_msg;
}				t_line;

int				read_file(int fd, t_map *map);
int				error_check(t_envars *env);
int				idx(int row, int col, int dim, int diff);
t_vert			m_v_mult(t_trmat m, t_vert vec);
t_trmat			trans_mat(double x_shift, double y_shift, double z_shift, int diff);
t_trmat			x_rot_mat(double theta, int transpose, int diff);
t_trmat			y_rot_mat(double theta, int transpose, int diff);
t_trmat			z_rot_mat(double theta, int transpose, int diff);
t_trmat			scale_mat(double x_scale, double y_scale, double z_scale, int diff);
int				init_img(t_envars *env, t_line *cpy);
void			img_pixel_put(t_image *img, double x, double y, int color);
void			clear_img(t_image *img);
void			clear_zbuf(t_map *map);
void			put_info(t_envars *env);
void			system_status(t_envars *env);
double			ft_lint(double start, double end, double decimal_percent);
int				color_lint(int c1, int c2, double decimal_percent);
double			get_line_pcnt(double start, double end, double curr);
int				calc_vert_color(t_envars *env, t_map *map, t_vert curr_vert);
void			toggle_colors(t_envars *env);
void			color_status(t_envars *env);
int				render(t_envars *env);
int				keydown_hook(int key, t_envars *env);
int				key_pressed_hook(int key, t_envars *env);
int				init_mouse(t_envars *env, t_line *cpy);
int				mouse_pressed_hook(int button, int x, int y, t_envars *env);
int				mouse_released_hook(int button, int x, int y, t_envars *env);
int				mouse_moved_hook(int x, int y, t_envars *env);

#endif
