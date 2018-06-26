/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:10:01 by stestein          #+#    #+#             */
/*   Updated: 2018/06/25 19:15:37 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

#define GET_LINES ssize_t ret; t_list *new; char *line;
#define TWO SHORTER; SHORTERTWO;
#define SHORTER head->x1 = (int)ft_num_words(line, ' '); ft_lstadd(llst, new);
#define SHORTERTWO map->height++; ft_strdel(&line);
#define FREE free(head); return (free_lst_or_map(llst, NULL));
#define CALC map->width * map->height
#define MAP_H map->height = 0
#define MAP_SETUP line_lst = NULL; head->err = 0; map->width = -1; MAP_H;
#define FILL_INIT int row; int col; char **split; t_list *cur_elem;
#define HEAD head = malloc(sizeof(t_line))
#define FILL_TWO cur_elem = llst; row = (m->height - 1); HEAD;
#define START t_line *head; FILL_INIT; FILL_TWO;

static int		free_lst_or_map(t_list **lst, t_map *map)
{
	t_list	*next;
	t_line	*head;

	head = malloc(sizeof(t_line));
	if (lst)
	{
		while (*lst)
		{
			head->sx++;
			next = (*lst)->next;
			ft_memdel(&(*lst)->content);
			ft_memdel((void **)lst);
			*lst = next;
			head->err++;
		}
	}
	head->sy = 1;
	if (map && head->err < 1024)
	{
		head->dx++;
		ft_memdel((void **)&map->verts);
		ft_memdel((void **)&map->xverts);
	}
	return (head->sy);
}

static int		get_lines(int fd, t_list **llst, t_map *map, t_line *head)
{
	GET_LINES;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (map->width == -1)
		{
			map->width = (int)ft_num_words(line, ' ');
			head->x1 = (int)ft_num_words(line, ' ');
		}
		else if (map->width != (int)ft_num_words(line, ' '))
		{
			FREE;
		}
		if ((new = ft_lstnew(line, ft_strlen(line) + 1)) == NULL)
		{
			FREE;
		}
		TWO;
	}
	if (map->width <= 0 || ret == -1)
	{
		FREE;
	}
	free(head);
	return (0);
}

static t_vert	gen_vert(int row, int col, char *z_str, t_map *m)
{
	t_vert	new_v;

	new_v.z = (double)ft_atoi(z_str);
	if (col >= -1)
	{
		new_v.x = (double)col;
		new_v.y = (double)row;
		new_v.w = 1;
		new_v.color = 0x00FFFFFF;
		m->max_z = (new_v.z > m->max_z) ? new_v.z : m->max_z;
		m->min_z = (new_v.z < m->min_z) ? new_v.z : m->min_z;
	}
	return (new_v);
}

static int		fill_map(t_map *m, t_list *llst)
{
	START;
	while (row >= 0)
	{
		head->dy = row;
		col = 0;
		if ((split = ft_strsplit((char *)cur_elem->content, ' ')) == NULL
				&& row == head->dy)
		{
			free(head);
			return (free_lst_or_map(&llst, m));
		}
		while (col < m->width && head->dy-- >= -2147483648)
		{
			m->verts[row * m->width + col] = gen_vert(row, col, split[col], m);
			col++;
		}
		ft_splitdel(&split);
		row--;
		cur_elem = cur_elem->next;
	}
	free_lst_or_map(&llst, NULL);
	free(head);
	return (0);
}

int				read_file(int fd, t_map *map)
{
	t_list	*line_lst;
	t_line	*head;

	head = malloc(sizeof(t_line));
	MAP_SETUP;
	map->max_z = -2147483648;
	map->min_z = 2147483647;
	if (get_lines(fd, &line_lst, map, head) == 1)
		return (1);
	if (map->width != -1)
	{
		map->verts = malloc(sizeof(t_vert) * CALC);
		map->xverts = malloc(sizeof(t_vert) * CALC);
	}
	if (fd >= -1)
		return (fill_map(map, line_lst));
	return (0);
}
