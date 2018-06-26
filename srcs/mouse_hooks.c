/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 19:39:09 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 18:57:00 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mouse_setup(t_envars *env, t_mouse *new_mouse, t_line *cpy)
{
	if (error_check(env) == 1)
	{
		cpy->x0 = 0;
		env->c_min = 0;
		new_mouse->is_pressed = 0;
		new_mouse->prev_x = 0;
		new_mouse->prev_y = 0;
		new_mouse->x = 0;
		cpy->x1 = new_mouse->x;
		new_mouse->y = 0;
	}
}

int		init_mouse(t_envars *env, t_line *cpy)
{
	t_mouse		*new_mouse;

	if (error_check(env) == 1)
	{
		new_mouse = &env->mouse;
		mouse_setup(env, new_mouse, cpy);
		return (1);
	}
	return (0);
}

// responsible for the data from the mlx_hook() function, which returns
// 3 ints: key pressed, x, y
// The data returned is based upon having (0,0) at the bottom left
// Remember the image's format has (0,0) at the top left
// left click - 1
// right click - 2
// scroll down - 4
// scroll up - 5
// scroll right - 6
// scroll left - 7

int		mouse_pressed_hook(int button, int x, int y, t_envars *env)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && error_check(env) == 1)
	{
		if ((button == 1 || button == 2) && error_check(env) == 1)
		{
			(&env->mouse)->is_pressed = 1;
			(&env->mouse)->x = x;
			(&env->mouse)->y = y;
		}
		if (button == 4 && error_check(env) == 1)
		{
			env->x_sca -= 1;
			env->y_sca -= 1;
			env->z_sca -= 1;
		}
		if (button == 5 && error_check(env) == 1)
		{
			env->x_sca += 1;
			env->y_sca += 1;
			env->z_sca += 1;
		}
		if ((button == 4 || button == 5) && error_check(env) == 1)
			render(env);
	}
	return (0);
}

int		mouse_released_hook(int button, int x, int y, t_envars *env)
{
	t_mouse		*mouse;

	if (error_check(env) == 1)
	{
		mouse = &env->mouse;
		(void)button;
		(void)x;
		(void)y;
		mouse->is_pressed = 0;
	}
	return (0);
}

int		mouse_moved_hook(int x, int y, t_envars *env)
{
	t_mouse		*mouse;

	mouse = &env->mouse;
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && error_check(env) == 1)
	{
		mouse->prev_x = mouse->x;
		mouse->prev_y = mouse->y;
		mouse->x = x;
		mouse->y = y;
		if (mouse->is_pressed && error_check(env) == 1)
		{
			env->y_rot -= (mouse->prev_x - x) / 150;
			env->x_rot += (mouse->prev_y - y) / 150;
		}
		if (mouse->is_pressed && error_check(env) == 1)
			render(env);
	}
	return (0);
}
