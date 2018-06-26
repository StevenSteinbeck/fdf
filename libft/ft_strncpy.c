/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:47:43 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 10:35:38 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	char			*s;

	s = (char *)s2;
	i = 0;
	while (s[i] != '\0' && (i < len))
	{
		s1[i] = s[i];
		i++;
	}
	while (i < len)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
