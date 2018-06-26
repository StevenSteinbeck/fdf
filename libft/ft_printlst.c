/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:40:09 by stestein          #+#    #+#             */
/*   Updated: 2018/05/29 15:40:09 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list **head)
{
	t_list *node;

	node = *head;
	while (node)
	{
		ft_putstr((char *)node->content);
		ft_putchar('\n');
		node = node->next;
	}
}
