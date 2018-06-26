/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insrt_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:58:45 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 16:11:25 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insrt_to_str(char **s1, char *s2)
{
	char *str;
	char *s1cpy;
	char *new;
	char i;

	i = '0';
	if ((!s1 || !s2) && i == '0')
		return ;
	new = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1);
	str = new;
	s1cpy = *s1;
	while (*s2 && i == '0')
		*str++ = *s2++;
	while (*s1cpy && i == '0')
		*str++ = *s1cpy++;
	*str = '\0';
	free(*s1);
	*s1 = new;
}
