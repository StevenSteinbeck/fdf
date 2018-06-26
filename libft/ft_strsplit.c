/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 08:58:50 by stestein          #+#    #+#             */
/*   Updated: 2018/06/06 13:11:07 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			cnt(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static int			starter(const char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static int			ender(const char *s, char c, int w)
{
	while (s[w] && s[w] != c)
		w++;
	return (w);
}

static char			*copyer(const char *s, char *str, int i, int w)
{
	int		p;

	p = 0;
	while (i < w)
	{
		str[p] = s[i];
		i++;
		p++;
	}
	str[p] = '\0';
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char **tab;

	STEVEN;
	tab = NULL;
	if (!s || (!(tab = (char **)malloc(sizeof(char *) * (cnt(s, c)) + 1))))
		return (NULL);
	tab[cnt(s, c)] = NULL;
	while (s[i])
	{
		i = starter(s, c, i);
		w = ender(s, c, i);
		if (s[i] == '\0')
			return (tab);
		str = (char *)malloc(sizeof(*str) * (w - i) + 1);
		if (str == NULL)
			return (NULL);
		str = copyer(s, str, i, w);
		tab[pos] = str;
		pos++;
		i = w - 1;
		i++;
	}
	return (tab);
}
