/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   austin_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:07:24 by stestein          #+#    #+#             */
/*   Updated: 2018/05/03 16:37:35 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		word_count(char const *s, char c)
{
	int i;
	int ret;

	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			ret++;
		i++;
	}
	return (ret);
}

char	*word_copy(const char *str, char *word, int i, int word_length)
{
	int x;
	int icpy;

	icpy = i;
	x = 0;
	while (word_length > 0)
	{
		word[x] = str[i];
		word_length--;
		x++;
		i++;
	}
	word[x] = '\0';
	return (word);
}
	

char	**ft_strsplit(const char *str, char letter)
{
	int i;
	int x;
	int w_count = word_count(str, letter);
	char *word;
	char **tab;
	int	word_length;
	int	icpy;

	if (!(tab = (char **)malloc(sizeof(char *) * w_count + 1)))
		return (NULL);
	x = 0;
	i = 0;
	icpy = 0;
	word_length = 0;
	tab[w_count] = 0;
	while (str[i])
	{
		while (str[i] == letter)
			i++;
		icpy = i;
		while (str[i] != letter && str[i])
		{
			i++;
			word_length++;
		}
		if ((word = (char *)malloc(sizeof(char) * word_length)) == 0)
			return (NULL);
		tab[x] = word_copy(str, word, icpy, word_length);
		if (x + 1 == w_count)
			break ;
		x++;
		word_length = 0;
	}
	return (tab);
}
		
/*int		main()
{
	char **tab;
	int x = 0;
	char str[20] = "Hello World How Are\0";
	char	c = ' ';

	tab = str_split(str, c);
	while (tab[x] != 0)
	{
		printf("%s", tab[x]);
		x++;
	}
	return (1);
}
*/
