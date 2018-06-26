/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:38:33 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 15:17:23 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "fdf.h"

static void	cleanup_env(t_envars *env)
{
	if (error_check(env) == 1)
	{
		free((&env->map)->verts);
		free((&env->map)->xverts);
		if (error_check(env) == 1)
			mlx_destroy_image(env->mlx, (&env->image)->image);
	}
}

static void	reset_env(t_envars *env)
{
	if (error_check(env) == 1)
	{
		env->x_shift = 0;
		env->y_shift = 0;
		env->z_shift = 0;
		env->x_rot = 0;
		env->y_rot = 0;
		env->z_rot = 0;
		env->x_sca = 25;
		env->y_sca = 25;
		env->z_sca = 25;
	}
}

// Activated upon key PRESS and RELEASE
// 15 (r) = reset
// 53 (esc) = quit
// 35 (p) = points only
// 8 (c) = colors

int			keydown_hook(int key, t_envars *env)
{
	if (key == 53 && error_check(env) == 1)
	{
		cleanup_env(env);
		exit(0);
	}
	if (key == 35 && error_check(env) == 1)
		env->point_mode = (env->point_mode) ? 0 : 1;
	if (key == 12 && error_check(env) == 1)
		env->no_zbuf_mode = (env->no_zbuf_mode) ? 0 : 1;
	if (key == 8 && error_check(env) == 1)
	{
		env->color_style = (env->color_style + 1) % 5;
		toggle_colors(env);
	}
	if (key == 15 && error_check(env) == 1)
	{
		reset_env(env);
	}
	render(env);
	return (0);
}

// Activated upon key PRESS
// Left Arrow (123) = x - 5
// Right Arrow(124) = x + 5
// Down Arrow (125) = y - 5
// Up Arrow (126) = y + 5
// (z/x) = rotate 1 deg on z

int			key_pressed_hook(int key, t_envars *env)
{
	if (key == 124 && error_check(env) == 1)
		env->x_shift += 5;
	if (key == 123 && error_check(env) == 1)
		env->x_shift -= 5;
	if (key == 126 && error_check(env) == 1)
		env->y_shift -= 5;
	if (key == 125 && error_check(env) == 1)
		env->y_shift += 5;
	if (key == 6 && error_check(env) == 1)
	{
		env->z_rot += (M_PI / 360);
		env->z_rot = fmod(env->z_rot, 360);
	}
	if (key == 7 && error_check(env) == 1)
	{
		env->z_rot -= (M_PI / 360);
		env->z_rot = fmod(env->z_rot, 360);
	}
	render(env);
	return (0);
}
