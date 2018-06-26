/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   austin_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:43:35 by stestein          #+#    #+#             */
/*   Updated: 2018/04/30 13:55:57 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return (str);
}

char	*ft_itoa(int n)
{
	char 	ret[10];
	char	*str;
	int		neg;
	int i = 0;

	neg = 1;
	if (n < 0)
	{
		neg = -1;
		n = n * -1;
	}
	while (n > 9)
	{
		ret[i] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	ret[i] = '0' + (n % 10);
	if (neg == -1)
	{
		ret[i + 1] = '-';
		ret[i + 2] = '\0';
	}
	if (neg == 1)
		ret[i + 1] = '\0';
	if (n < 0)
		str = (char *)malloc(sizeof(char) * i + 3);
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	str = strrev(ret);
	printf("%s\n", str);
	return (str);
}
	
/*int		main()
{
	char *result = NULL;
	int number = 123;
	int neg_number = -1234567;
	int i = 0;

	result = ft_itoa(number);
	return (0);
}*/

		
