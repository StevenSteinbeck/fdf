/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:58:05 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 18:48:08 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	t_libft		*head;
	uintmax_t	i;
	size_t		size;
	char		*ret;

	head = malloc(sizeof(t_libft));
	i = value;
	size = 1;
	head->i = 0;
	while ((i /= base) && head->i < 10)
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = value;
	head->i = i;
	ret[--size] = str[i % base];
	while ((i /= base))
		ret[--size] = str[i % base];
	free(head);
	return (ret);
}
