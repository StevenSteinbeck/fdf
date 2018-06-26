/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:49:23 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 10:21:42 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t len)
{
	char			*c1;
	char			*c2;
	unsigned int	i;

	i = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	if (c2 < c1)
	{
		while (len--)
			c1[len] = c2[len];
	}
	else
		ft_memcpy(c1, c2, len);
	return (s1);
}
