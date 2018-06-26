/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_xform_matrices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:32:45 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 18:58:09 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft.h>
#include "fdf.h"

/*
**	A translation matrix takes the following form:
**	1	0	0	vx
**	0	1	0	vy
**	0	0	1	vz
**	0	0	0	1
**
**	vx, vy, vz represent translations in the x, y, and z axes respectively
*/

t_trmat	trans_mat(double x_shift, double y_shift, double z_shift, int diff)
{
	t_trmat	trans_mat;

	ft_bzero(trans_mat.m, sizeof(trans_mat.m));
	while (diff >= 1)
	{
		trans_mat.rows = 4;
		trans_mat.cols = 4;
		if (diff == 1)
		{
			trans_mat.m[idx(0, 0, 4, diff)] = 1;
			trans_mat.m[idx(1, 1, 4, diff)] = 1;
			trans_mat.m[idx(2, 2, 4, diff)] = 1;
			trans_mat.m[idx(0, 3, 4, diff)] = x_shift;
			trans_mat.m[idx(1, 3, 4, diff)] = y_shift;
			trans_mat.m[idx(2, 3, 4, diff)] = z_shift;
			trans_mat.m[idx(3, 3, 4, diff)] = 1;
		}
		diff--;
	}
	return (trans_mat);
}

/*
**	Rotation about the x-axis:
**	1		0		0		0
**	0		cos		-sin	0
**	0		sin		cos		0
**	0		0		0		1
**
**	Note: for anti rotation switch the sin and -sin
**	Note 2: theta is measured in radians
*/

t_trmat	x_rot_mat(double theta, int transpose, int diff)
{
	t_trmat trans_mat;

	ft_bzero(trans_mat.m, sizeof(trans_mat.m));
	while (diff >= 1)
	{
		trans_mat.rows = 4;
		trans_mat.cols = 4;
		if (diff == 1)
		{
			trans_mat.m[idx(0, 0, 4, diff)] = 1;
			trans_mat.m[idx(1, 1, 4, diff)] = cos(theta);
			trans_mat.m[idx(1, 2, 4, diff)] =
				(transpose) ? -sin(theta) : sin(theta);
			trans_mat.m[idx(2, 1, 4, diff)] =
				(transpose) ? sin(theta) : -sin(theta);
			trans_mat.m[idx(2, 2, 4, diff)] = cos(theta);
			trans_mat.m[idx(3, 3, 4, diff)] = 1;
		}
		diff--;
	}
	return (trans_mat);
}

/*
**	Rotation about the y-axis:
**	cos		0		sin		0
**	0		1		0		0
**	-sin	0		cos		0
**	0		0		0		1
**
**	Note: for anti rotation switch the sin and -sin
**	Note 2: theta is measured in radians
*/

t_trmat	y_rot_mat(double theta, int transpose, int diff)
{
	t_trmat	trans_mat;

	ft_bzero(trans_mat.m, sizeof(trans_mat.m));
	while (diff >= 1)
	{
		trans_mat.rows = 4;
		trans_mat.cols = 4;
		if (diff == 1)
		{
			trans_mat.m[idx(0, 0, 4, diff)] = cos(theta);
			trans_mat.m[idx(0, 2, 4, diff)] =
				(transpose) ? sin(theta) : -sin(theta);
			trans_mat.m[idx(1, 1, 4, diff)] = 1;
			trans_mat.m[idx(2, 0, 4, diff)] =
				(transpose) ? -sin(theta) : sin(theta);
			trans_mat.m[idx(2, 2, 4, diff)] = cos(theta);
			trans_mat.m[idx(3, 3, 4, diff)] = 1;
		}
		diff--;
	}
	return (trans_mat);
}

/*
**	Rotation about the z-axis:
**	cos		-sin	0		0
**	sin		cos		0		0
**	0		0		1		0
**	0		0		0		1
**
**	Note: for anti rotation switch the sin and -sin
**	Note 2: theta is measured in radians
*/

t_trmat	z_rot_mat(double theta, int transpose, int diff)
{
	t_trmat	trans_mat;

	ft_bzero(trans_mat.m, sizeof(trans_mat.m));
	while (diff >= 1)
	{
		trans_mat.rows = 4;
		trans_mat.cols = 4;
		if (diff == 1)
		{
			ft_bzero(trans_mat.m, sizeof(trans_mat.m));
			trans_mat.m[idx(0, 0, 4, diff)] = cos(theta);
			trans_mat.m[idx(0, 1, 4, diff)] =
				(transpose) ? -sin(theta) : sin(theta);
			trans_mat.m[idx(1, 0, 4, diff)] =
				(transpose) ? sin(theta) : -sin(theta);
			trans_mat.m[idx(1, 1, 4, diff)] = cos(theta);
			trans_mat.m[idx(2, 2, 4, diff)] = 1;
			trans_mat.m[idx(3, 3, 4, diff)] = 1;
		}
		diff--;
	}
	return (trans_mat);
}

/*
**	Scaling matrix:
**	Sx	0	0	0
**	0	Sy	0	0
**	0	0	Sz	0
**	0	0	0	1
**
**	Sx, Sy, Sz represent scalings that will be performed on x, y, and z
*/

t_trmat	scale_mat(double x_scale, double y_scale, double z_scale, int diff)
{
	t_trmat trans_mat;

	ft_bzero(trans_mat.m, sizeof(trans_mat.m));
	while (diff >= 1)
	{
		trans_mat.rows = 4;
		trans_mat.cols = 4;
		if (diff == 1)
		{
			trans_mat.m[idx(0, 0, 4, diff)] = x_scale;
			trans_mat.m[idx(1, 1, 4, diff)] = y_scale;
			trans_mat.m[idx(2, 2, 4, diff)] = z_scale;
			trans_mat.m[idx(3, 3, 4, diff)] = 1;
		}
		diff--;
	}
	return (trans_mat);
}
