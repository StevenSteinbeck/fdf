/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:45:47 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 10:39:13 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (str[i] == to_find[i] && str[i] == '\0')
		return ((char *)&str[i]);
	while (str[i])
	{
		j = i;
		while (str[j] == to_find[j - i] && str[j])
			j++;
		if (to_find[j - i] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
