/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:31:33 by stestein          #+#    #+#             */
/*   Updated: 2018/06/22 12:31:43 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchrpos(const char *s, int c)
{
	int		i;
	char	c2;

	i = 0;
	c2 = (char)c;
	while (s[i] != '\0' && c2 != s[i])
		i++;
	if (s[i] != c2)
		return (-1);
	else
		return (i);
}
