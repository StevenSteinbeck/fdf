/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:43:58 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 15:13:01 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void	put_info(t_envars *env)
{
	mlx_string_put(env->mlx, env->win, 10, 0, 0x00FF0000, "USAGE GUIDE:");
	mlx_string_put(env->mlx, env->win, 10, 30, 0x00FFFFFF, "Mouse drag: rotate x/y axis");
	mlx_string_put(env->mlx, env->win, 10, 50, 0x00FFFFFF, "Mouse scroll: zoom");
	mlx_string_put(env->mlx, env->win, 10, 70, 0x00FFFFFF, "Arrow Keys: move around");
	mlx_string_put(env->mlx, env->win, 10, 90, 0x00FFFFFF, "Mouse scroll: zoom");
	mlx_string_put(env->mlx, env->win, 10, 110, 0x00FFFFFF, "Z/X Keys: spin around z axis");
	mlx_string_put(env->mlx, env->win, 10, 130, 0x00FFFFFF, "c: color modes");
	mlx_string_put(env->mlx, env->win, 10, 150, 0x00FFFFFF, "p: show only points");
	mlx_string_put(env->mlx, env->win, 10, 170, 0x00FFFFFF, "r: reset everything");
	mlx_string_put(env->mlx, env->win, 10, 190, 0x00FF0000, "ESC: quit");	
}

int		error_check(t_envars *env)
{
	int	*ptr;
	int i;

	i = 0;
	ptr = (int *)malloc(sizeof(int) * 10);
	if (env == 0)
	{
		write(2, "ERROR - MASSIVE CRASH", 22);
		free(ptr);
		return (0);
	}
	if (env != 0)
	{
		ptr[i] = 0;
		i++;
	}
	env->fd += i - 1;
	free(ptr);
	return (1);
}

void	color_status(t_envars *env)
{
	if (env->color_style == 1)
		mlx_string_put(env->mlx, env->win, 666, 88, 0xFF0000, "RED APPLIED");
	if (env->color_style == 2)
		mlx_string_put(env->mlx, env->win, 666, 88, 0x00FFFF00, "YELLOW APPLIED");
	if (env->color_style == 3)
		mlx_string_put(env->mlx, env->win, 666, 88, 0x007F7F7F, "GRAY APPLIED");
	if (env->color_style == 4)
		mlx_string_put(env->mlx, env->win, 666, 88, 0x000000FF, "BLUE APPLIED");
	system_status(env);
}

void	system_status(t_envars *env)
{
	if (env->point_mode != 0)
		mlx_string_put(env->mlx, env->win, 666, 68, 0xFFFFFF, "POINTS ONLY");
	if (env->no_zbuf_mode != 0)
		mlx_string_put(env->mlx, env->win, 666, 48, 0xFFFFFF, "NO ZBUFFERING");
}
