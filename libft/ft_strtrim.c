/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:58:14 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 10:42:19 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length_count(const char *str)
{
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (str[length])
		length++;
	length--;
	while (str[length] == ' ' || str[length] == '\t' || str[length] == '\n')
		length--;
	if (length == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
		length--;
	}
	return (length);
}

char			*ft_strtrim(char const *s)
{
	int		length;

	TRIM;
	if (s == NULL)
		return (NULL);
	length = length_count(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	str = (char *)malloc(sizeof(*str) * (length + 2));
	if (str == NULL)
		return (NULL);
	n = 0;
	while (length + 1 > 0)
	{
		str[n] = s[i];
		length--;
		n++;
		i++;
	}
	str[n] = '\0';
	return (str);
}
