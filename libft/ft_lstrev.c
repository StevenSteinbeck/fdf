/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:43:15 by stestein          #+#    #+#             */
/*   Updated: 2018/06/23 19:43:21 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	ft_lstrev(t_list **begin_list)
{
	t_list *new_begin;
	t_list *temp_next;

	if (begin_list)
	{
		new_begin = NULL;
		while (*begin_list)
		{
			temp_next = (*begin_list)->next;
			(*begin_list)->next = new_begin;
			new_begin = *begin_list;
			*begin_list = temp_next;
		}
		*begin_list = new_begin;
	}
}
