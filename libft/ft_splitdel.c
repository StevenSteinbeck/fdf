/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:41:22 by stestein          #+#    #+#             */
/*   Updated: 2018/06/22 12:41:29 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitdel(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	if (split)
	{
		str = *split;
		while (*str)
		{
			ft_strdel(str);
			i++;
			str = &(*split)[i];
		}
		ft_memdel((void **)split);
	}
}
