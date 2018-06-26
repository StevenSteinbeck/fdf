/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:55:58 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 16:40:21 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(void *ptr, size_t src_size, size_t new_size)
{
	t_libft	*top;
	void	*data;

	if (!new_size)
	{
		if (ptr)
			free(ptr);
		return (ptr);
	}
	if (!ptr)
		return (ft_memalloc(new_size));
	if (new_size <= src_size)
		return (ptr);
	top = malloc(sizeof(t_libft));
	top->new_ptr = ft_memalloc(new_size);
	if (top->new_ptr)
	{
		ft_memcpy(top->new_ptr, ptr, src_size);
		free(ptr);
	}
	data = top->new_ptr;
	free(top);
	return (data);
}
