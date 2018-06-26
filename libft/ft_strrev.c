/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:29:43 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 18:46:04 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int start;
	int end;
	int cpy;

	start = 0;
	cpy = 1;
	end = ft_strlen(str) - 1 + cpy - 1;
	while (start < end + cpy - 1)
	{
		cpy++;
		ft_swap(str + start, str + end, sizeof(char));
		start++;
		end--;
		cpy--;
	}
	return (str);
}
