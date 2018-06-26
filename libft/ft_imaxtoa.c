/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:59:16 by stestein          #+#    #+#             */
/*   Updated: 2018/06/22 12:20:16 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t value)
{
	t_num		*top;
	char		*ret;

	top = malloc(sizeof(t_num));
	top->hex = (value < 0) ? -value : value;
	top->val = 1 + (value < 0);
	while ((top->hex /= 10))
		top->val++;
	ret = (char *)malloc(sizeof(char) * (top->val + 1));
	ret[top->val] = '\0';
	top->hex = (value < 0) ? -value : value;
	ret[--top->val] = "0123456789"[top->hex % 10];
	while ((top->hex /= 10))
		ret[--top->val] = "0123456789"[top->hex % 10];
	if (value < 0)
		ret[--top->val] = '-';
	free(top);
	return (ret);
}
