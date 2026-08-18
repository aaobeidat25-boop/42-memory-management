/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:59:54 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/16 14:24:49 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	validcharset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	wordscount(char *str, char *charset)
{
	int		numofwords;
	int		i;
	int		j;

	i = 0;
	j = 0;
	numofwords = 0;
	while (str[i])
	{
		if (validcharset(str[i], charset) && j == 0)
		{
			numofwords++;
			j = 1;
		}
		else if (!validcharset(str[i], charset))
			j = 0;
		i++;
	}
	return (numofwords);
}

int	*array(int *arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

int	extract_word(char *str, char *charset, char **ptr, int *arr)
{
	arr[3] = 0;
	arr[4] = arr[0];
	while (str[arr[0]] && !(validcharset(str[arr[0]], charset)))
	{
		arr[3]++;
		arr[0]++;
	}
	ptr[arr[1]] = malloc((arr[3] + 1) * sizeof(char));
	if (!ptr[arr[1]])
		return (0);
	arr[0] = arr[4];
	arr[2] = 0;
	while (arr[2] < arr[3])
	{
		ptr[arr[1]][arr[2]] = str[arr[0]];
		arr[2]++;
		arr[0]++;
	}
	ptr[arr[1]][arr[2]] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		arr[5];
	char	**ptr;

	array(arr);
	ptr = malloc((wordscount(str, charset) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (str[arr[0]])
	{
		while (str[arr[0]] && validcharset(str[arr[0]], charset))
			arr[0]++;
		if (!str[arr[0]])
			break ;
		if (!extract_word(str, charset, ptr, arr))
			return (NULL);
		arr[1]++;
	}
	ptr[arr[1]] = NULL;
	return (ptr);
}
