/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:20:36 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 12:45:04 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_skipspace(char *str)
{
	int		i;
	char	*new;
	int		s;

	i = 0;
	s = 0;
	while (str[i] && str[i] == ' ')
		i++;
	new = (char *)malloc(sizeof(*new) * ft_strlen(str) - i + 1);
	while (new[s])
	{
		new[s] = str[i];
		s++;
		i++;
	}
	return (new);
}
