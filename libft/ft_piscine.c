/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piscine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:26:21 by stestein          #+#    #+#             */
/*   Updated: 2018/03/13 12:33:37 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_error(void)
{
	int		i;
	char	*e;

	i = 0;
	e = "ERROR - ARGV needs a value. Ex: ./a.out \"Hello\"";
	while (e[i])
	{
		ft_putchar(e[i]);
		i++;
	}
}

char		ft_piscine(char const *str)
{
	int		i;
	char	*s;
	char	*e;

	s = "┈┈╱▔▔▔▔▔╲┈┈┈HM┈HM\n┈╱┈┈╱▔╲╲╲▏┈┈┈HMMM\n╱┈┈╱━╱▔▔▔▔▔╲━╮┈┈ \
		\n▏┈▕┃▕╱▔╲╱▔╲▕╮┃┈┈\n▏┈▕╰━▏▊▕▕▋▕▕━╯┈┈\n╲┈┈╲╱▔╭╮▔▔┳╲╲┈┈┈ \
		\n ┈╲┈┈▏╭━━━━╯▕▕┈┈┈\n┈┈╲┈╲▂▂▂▂▂▂╱╱┈┈┈\n┈┈┈┈▏┊┈┈┈┈┊┈┈┈╲┈ \
		\n ┈┈┈┈▏┊┈┈┈┈┊▕╲┈┈╲\n┈╱▔╲▏┊┈┈┈┈┊▕╱▔╲▕\n┈▏ ┈┈┈╰┈┈┈┈╯┈┈┈▕▕ \
		\n ┈╲┈┈┈╲┈┈┈┈╱┈┈┈╱┈╲\n┈┈╲┈┈▕▔▔▔▔▏┈┈╱╲╲╲▏\n┈╱▔┈┈▕┈┈┈┈▏┈┈▔╲▔▔ \
		\n ┈╲▂▂▂╱┈┈┈┈╲▂▂▂╱┈";
	e = "ERROR - ARGV needs a value. Ex: ./a.out \"Hello\"";
	i = 0;
	if (str && str[i])
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	i = 0;
	if (!(str && str[i]))
		ft_error();
	return (0);
}
