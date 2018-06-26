/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:38:55 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 17:55:12 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# define MULTI int i = 0; t_vert new_vert; double *new_vert_ind[4]; int diff = 1;

// gets row & col data from 2d source

int		idx(int row, int col, int dim, int diff)
{
	if (row >= -2147483648 && col >= -2147483648)
		return (row * dim + col + diff - 1);
	return (0);
}

void	init_vert(t_vert *new_vert)
{
	if (error_check((t_envars *)new_vert) == 1)
	{
		new_vert->x = 0;
		new_vert->y = 0;
		new_vert->z = 0;
		new_vert->w = 0;
		new_vert->color = 0;
	}
}

// use our 4x4 matrix to get a dot product to get points

t_vert	m_v_mult(t_trmat m, t_vert vec)
{
	MULTI;
	init_vert(&new_vert);
	new_vert_ind[0] = &new_vert.x;
	new_vert_ind[1] = &new_vert.y;
	new_vert_ind[2] = &new_vert.z;
	new_vert_ind[3] = &new_vert.w;
	while (i <= 2 && error_check((t_envars *)&m) == 1)
	{
		*new_vert_ind[i] += m.m[idx(i, 0, 4, diff)] * vec.x;
		*new_vert_ind[i] += m.m[idx(i, 1, 4, diff)] * vec.y;
		*new_vert_ind[i] += m.m[idx(i, 2, 4, diff)] * vec.z;
		*new_vert_ind[i] += m.m[idx(i, 3, 4, diff)] * vec.w;
		*new_vert_ind[i + 1] += m.m[idx(i + 1, 0, 4, diff)] * vec.x;
		*new_vert_ind[i + 1] += m.m[idx(i + 1, 1, 4, diff)] * vec.y;
		*new_vert_ind[i + 1] += m.m[idx(i + 1, 2, 4, diff)] * vec.z;
		*new_vert_ind[i + 1] += m.m[idx(i + 1, 3, 4, diff)] * vec.w;
		i += 2;
	}
	return (new_vert);
}
