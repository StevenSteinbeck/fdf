/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:03:35 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 10:37:13 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (str[i] == to_find[i] && str[i] == '\0')
		return ((char *)&str[i]);
	while (str[i] && i <= len)
	{
		j = i;
		while (str[j] == to_find[j - i] && str[j] && j < len)
			j++;
		if (to_find[j - i] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
