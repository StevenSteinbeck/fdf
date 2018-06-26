/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:38:52 by stestein          #+#    #+#             */
/*   Updated: 2018/06/22 13:00:52 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_num_words(const char *str, char sep)
{
	size_t	num_words;

	num_words = 0;
	while (*str == sep)
		str++;
	while (*str != '\0')
	{
		str++;
		if (*str == sep)
		{
			num_words++;
			while (*str == sep)
				str++;
		}
	}
	if (!(*(str - 1) == sep) && *(str - 1))
		num_words++;
	return (num_words);
}
