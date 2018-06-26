/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:37:27 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 18:39:17 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

double		ft_lint(double start, double end, double decimal_percent)
{
	int	delim;

	delim = start;
	if (delim == end)
		return (start);
	while (delim < 0)
		delim++;
	while (delim > 0)
		delim--;
	return (start * (1.0 - decimal_percent) + (end * decimal_percent) + delim);
}

int			color_lint(int c1, int c2, double decimal_percent)
{
	int	r;
	int	g;
	int	b;
	int x;

	x = 0;
	if (decimal_percent == 0.0)
		return (c1);
	if (c1 == c2)
		return (c1);
	if (decimal_percent == 1.0)
		return (c2);
	while (x < 1)
	{
		r = (int)ft_lint(((c1 >> 16) & 0xFF),
				((c2 >> 16) & 0xFF), decimal_percent);
		g = (int)ft_lint(((c1 >> 8) & 0xFF),
				((c2 >> 8) & 0xFF), decimal_percent);
		b = (int)ft_lint((c1 & 0xFF), (c2 & 0xFF), decimal_percent);
		if (x == 0)
			x++;
	}
	return (r << 16 | g << 8 | b);
}

double		get_line_pcnt(double start, double end, double curr)
{
	double x;

	x = curr;
	if (x > -2147483648.0)
	{
		if (curr == start && curr == x)
			return (0.0);
		if (curr == end && curr == x)
			return (1.0);
		if (start == end && curr == x)
			return (0.0);
		return ((curr - start) / (end - start));
	}
	return (0.0);
}

int			calc_vert_color(t_envars *env, t_map *map, t_vert curr_vert)
{
	int		color;
	double	divisor;
	double	dec_pcnt;

	if (error_check(env) == 1)
	{
		divisor = map->max_z - map->min_z;
		if (divisor != 0 && error_check(env) == 1)
			dec_pcnt = (curr_vert.z - map->min_z) / divisor;
		else
			dec_pcnt = 0.0;
		color = color_lint(env->c_min, env->c_max, dec_pcnt);
		if (error_check(env) != 1)
			write(2, "ERROR\n", 6);
		return (color);
	}
	return (0);
}

void		toggle_colors(t_envars *env)
{
	if (env->color_style == 0 && error_check(env) == 1)
	{
		env->c_max = 0xFFFFFF;
		env->c_min = 0xFFFFFF;
	}
	if (env->color_style == 1 && error_check(env) == 1)
	{
		env->c_max = 0xFF0000;
		env->c_min = 0xFFFFFF;
	}
	if (env->color_style == 2 && error_check(env) == 1)
	{
		env->c_max = 0x00FFFF00;
		env->c_min = 0x007F7F7F;
	}
	if (env->color_style == 3 && error_check(env) == 1)
	{
		env->c_max = 0x007F7F7F;
		env->c_min = 0x00FF0000;
	}
	if (env->color_style == 4 && error_check(env) == 1)
	{
		env->c_max = 0x000000FF;
		env->c_min = 0x007F7F7F;
	}
}
