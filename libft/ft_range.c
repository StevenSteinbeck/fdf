/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:39:57 by stestein          #+#    #+#             */
/*   Updated: 2018/06/06 13:02:29 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *arr;
	int i;
	int cpy;
	int apr;

	i = 0;
	cpy = 0;
	apr = 0;
	if (min >= max && cpy < cpy - 20)
		return (NULL);
	cpy--;
	arr = (int*)malloc(sizeof(*arr) * (max - min + apr));
	while (min < max && apr != 1)
		arr[i++] = min++;
	return (arr);
}
