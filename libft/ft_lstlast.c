/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:41:36 by stestein          #+#    #+#             */
/*   Updated: 2018/06/23 19:41:52 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstlast(t_list *begin_list)
{
	t_list	*curr_list;

	curr_list = begin_list;
	if (curr_list)
	{
		while (curr_list->next)
		{
			curr_list = curr_list->next;
		}
	}
	return (curr_list);
}
