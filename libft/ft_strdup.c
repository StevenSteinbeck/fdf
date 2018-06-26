/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:20:02 by stestein          #+#    #+#             */
/*   Updated: 2018/06/22 12:22:18 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	dup = (char*)malloc(sizeof(*dup) * (size + 1));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, str);
	return (dup);
}
