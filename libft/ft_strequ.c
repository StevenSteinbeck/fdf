/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:11:54 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 10:27:02 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (!(s1[i] || s2[i]))
		return (1);
	while (s1[i] && s2[i])
	{
		if (ft_strcmp(s1, s2) != 0)
			return (0);
		i++;
	}
	return (1);
}
