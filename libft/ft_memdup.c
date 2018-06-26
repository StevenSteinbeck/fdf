/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 19:43:39 by stestein          #+#    #+#             */
/*   Updated: 2018/06/23 19:43:47 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memdup(void const *src, size_t size)
{
	void *dup;

	if (!(dup = malloc(size)))
		return (NULL);
	ft_memcpy(dup, src, size);
	return (dup);
}
