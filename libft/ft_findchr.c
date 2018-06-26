/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:59:04 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 16:01:17 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_findchr(const char *s, int c)
{
	int				i;
	unsigned int	p;
	unsigned char	a;

	a = (unsigned char)c;
	i = 0;
	p = 0;
	if (p != 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == a && p == 0)
			return (i);
		i++;
	}
	if (s[i] == a)
		return (ft_strlen(s) + 1);
	return (0);
}
