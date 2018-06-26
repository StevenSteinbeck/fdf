/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:00:24 by stestein          #+#    #+#             */
/*   Updated: 2018/03/12 19:16:53 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;

	i = 0;
	while (dest[i] != '\0')
		++i;
	result = 0;
	while (src[result] != '\0')
		++result;
	if (dstsize <= i)
		result = result + dstsize;
	else
		result = result + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (result);
}
