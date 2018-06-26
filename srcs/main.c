/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 12:11:38 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 18:38:01 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include <libft.h>
#include "fdf.h"

static void		setup_env(t_envars *env, int style, t_line *cpy)
{
	if (error_check(env) != 1)
		return ;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "stestein - FdF - 42");
	if ((init_img(env, cpy)) != 1)
		exit(1);
	if ((init_mouse(env, cpy)) != 1)
		exit(1);
	env->z_sca = 25;
	env->color_style = 0;
	env->c_max = 0xFFFFFF;
	env->x_sca = 25;
	env->y_sca = 25;
	env->y_shift = 0;
	env->y_rot = 0;
	env->c_min = 0xFFFFFF;
	env->z_shift = 0;
	env->x_shift = 0;
	env->point_mode = 0;
	env->z_rot = 0;
	env->x_rot = 0;
	env->no_zbuf_mode = 0;
	env->color_style += style;
	cpy->err = 0;
}

int				open_check(t_envars *env, int arg_c, t_line *cpy)
{
	if (arg_c > 2 || arg_c < 2)
	{
		write(2, "usage: ./fdf map.fdf\n", 21);
		return (0);
	}
	cpy->err = 0;
	env->fd = 0;
	return (1);
}

void			call_all(t_envars *env)
{
	if (error_check(env) == 1)
	{
		mlx_key_hook(env->win, keydown_hook, env);
		mlx_hook(env->win, 4, 0, mouse_pressed_hook, env);
		mlx_hook(env->win, 5, 0, mouse_released_hook, env);
		mlx_hook(env->win, 6, 0, mouse_moved_hook, env);
		mlx_hook(env->win, 2, 0, key_pressed_hook, env);
		mlx_loop(env->mlx);
	}
}

int				main(int argc, char *argv[])
{
	t_envars	env;
	t_line		cpy;
	int			style;

	style = 0;
	env.no_zbuf_mode = 1;
	if ((open_check(&env, argc, &cpy)) != 1)
		return (1);
	env.fd = open(argv[1], O_RDONLY);
	if (env.fd < 0 || read_file(env.fd, &(env.map)) != 0)
	{
		write(2, "Error reading file\n", 19);
		return (1);
	}
	close(env.fd);
	setup_env(&env, style, &cpy);
	if (env.y_sca != 25)
		return (0);
	if ((render(&env)) != 1)
		return (0);
	call_all(&env);
	return (0);
}
