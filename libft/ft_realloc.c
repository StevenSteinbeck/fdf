/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:09:57 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 16:23:41 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t src_size, size_t new_size)
{
	t_libft	*head;
	void	*data;

	head = malloc(sizeof(t_libft));
	if (!new_size)
	{
		if (ptr)
			free(ptr);
		return (ptr);
	}
	if (!ptr)
		return (malloc(new_size));
	if (new_size <= src_size)
		return (ptr);
	head->new_ptr = malloc(new_size);
	if (head->new_ptr)
	{
		ft_memcpy(head->new_ptr, ptr, src_size);
		free(ptr);
	}
	data = head->new_ptr;
	free(head);
	return (data);
}
