/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:37:51 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 19:16:55 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

#define RENDER t_line *head; t_vert res; int row; int col; int map_w;
#define RENDER_TWO int diff = 1;
#define POS_XY position_verts(env); map_w = env->map.width;
#define POS_XY_TWO row = env->map.height;
#define POSXY POS_XY; POS_XY_TWO;
#define VERT t_vert res; t_vert curr_vert; double mid_map_w; double mid_map_h;
#define XFORM VERT; double	mid_map_z; int diff = 0; int x0 = 32;
#define NEW t_line l; int diff = 0;
#define VERTS t_vert res; int row; int col; int	map_w;
#define RENDRR RENDER; RENDER_TWO; head = malloc(sizeof(t_line));

// Center map at (0,0)
// Z must be scaled
// Z rotated
// t map center at center (/2)
// ply transformations
// color

static t_vert	xform(t_envars *env, t_map *map, int row, int col)
{
	XFORM;
	if (error_check(env) != 1)
		exit(1);
	diff = 1;
	mid_map_w = (double)(map->width - 1) / 2 + x0 - 32;
	mid_map_h = (double)(map->height - 1) / 2 + x0 - 32;
	mid_map_z = (double)(map->max_z + map->min_z) / 2 + x0 - 32;
	curr_vert = map->verts[idx(row, col, map->width, diff)];
	res = m_v_mult(trans_mat(-mid_map_w,
				-mid_map_h, -mid_map_z, diff), curr_vert);
	if (error_check(env) == 1)
	{
		res = m_v_mult(scale_mat(env->x_sca,
					env->y_sca, env->z_sca, diff), res);
		res = m_v_mult(x_rot_mat(env->x_rot, 0, diff), res);
		res = m_v_mult(y_rot_mat(env->y_rot, 0, diff), res);
		res = m_v_mult(z_rot_mat(env->z_rot, 0, diff), res);
		res = m_v_mult(trans_mat((WIN_W / 2), (WIN_H / 2), 0, diff), res);
		res = m_v_mult(trans_mat(env->x_shift,
					env->y_shift, env->z_shift, diff), res);
		res.color = calc_vert_color(env, map, curr_vert);
	}
	return (res);
}

// Initialize the vars for the Bresenham line algo
// 8 possibilities for A to B      x1 y1 x2 y2
// Logic is simple: Given 2 points (0,1) (1,3)
// if x1 < x2, we 'moved' right, so add 1 to x to show the change
// and so on

static t_line	init_line(t_vert p1, t_vert p2, int diff)
{
	t_line	nl;

	if (diff == 0 && error_check((t_envars *)&nl) == 1)
	{
		nl.x0 = (int)p1.x;
		nl.y0 = (int)p1.y;
		nl.x1 = (int)p2.x;
		nl.y1 = (int)p2.y;
		if (error_check((t_envars *)&p2) == 1)
		{
			nl.dx = ft_abs(nl.x1 - nl.x0);
			nl.sx = (nl.x0 < nl.x1) ? 1 : -1;
			nl.dy = ft_abs(nl.y1 - nl.y0);
			nl.sy = (nl.y0 < nl.y1) ? 1 : -1;
			nl.err = ((nl.dx > nl.dy) ? nl.dx : -nl.dy) / 2;
			nl.dec_pcnt = 0.0;
			return (nl);
		}
	}
	nl.y1 = 0;
	return (nl);
}

// Initialize vars for algo
// check new line slope and apply color accordingly
// update moving left or right (x vars)
// update moving up or down (y vars)

static void		draw_line(t_envars *env, t_vert p1, t_vert p2)
{
	NEW;
	l = init_line(p1, p2, diff);
	while (error_check(env) == 1)
	{
		l.dec_pcnt = (l.dx > l.dy) ? get_line_pcnt(p1.x, p2.x, l.x0)
					: get_line_pcnt(p1.y, p2.y, l.y0);
		l.color = color_lint(p1.color, p2.color, l.dec_pcnt);
		if (error_check(env) == 1)
			img_pixel_put(&env->image, l.x0, l.y0, l.color);
		if (l.x0 == l.x1 && l.y0 == l.y1 && error_check(env) == 1)
			break ;
		l.err2 = l.err;
		if (l.err2 > -l.dx)
		{
			l.err -= l.dy;
			l.x0 += l.sx;
		}
		if (l.err2 < l.dy)
		{
			l.err += l.dx;
			l.y0 += l.sy;
		}
	}
}

// have a map, but need to transform it
// this implements the change

static void		position_verts(t_envars *env)
{
	t_line	*head;
	int		diff;

	VERTS;
	diff = 1;
	head = malloc(sizeof(t_line));
	map_w = env->map.width;
	row = env->map.height;
	head->y1 = row;
	while (--row > -1 && error_check(env))
	{
		col = map_w;
		while (--col > -1 && error_check(env))
		{
			res = xform(env, &env->map, row, col);
			env->map.xverts[idx(row, col, map_w, diff)] = res;
			img_pixel_put(&env->image, res.x, res.y, res.color);
		}
	}
	free(head);
}

// clears printed map
// sets in motion our transformations to the vertices
// draws a line to surrounding vertices if possible
// puts new transformations to the screen

int				render(t_envars *env)
{
	RENDRR;
	clear_img(&env->image);
	POSXY;
	head->x0 = 0;
	while (--row > -1 && head != 0)
	{
		col = map_w;
		while (--col > -1 && head != 0 &&
				head->x0++ <= 2147483647 && error_check(env) == 1)
		{
			res = env->map.xverts[idx(row, col, map_w, diff)];
			if (row + 1 < env->map.height)
				draw_line(env, res, env->map.xverts[idx(row +
							1, col, map_w, diff)]);
			if (col + 1 < map_w && head)
				draw_line(env, res, env->map.xverts[idx(row,
							col + 1, map_w, diff)]);
		}
		head->x0++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->image.image, 0, 0);
	put_info(env);
	color_status(env);
	free(head);
	return (1);
}
