/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:32:03 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/17 11:52:33 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_index(int *ind)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ind[i] = 0;
		i++;
	}
	return (ind);
}

int	counts_z(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		sz;

	i = 0;
	sz = 0;
	j = 0;
	while (sep[i])
	{
		sz++;
		i++;
	}
	sz += (size - 2) * sz;
	i = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			sz++;
			j++;
		}
		i++;
		j = 0;
	}
	return (sz);
}

void	increment(int *a, int *b)
{
	(*a)++;
	(*b)++;
}

char	*ffff(int size, int len)
{
	char	*ptr;

	if (size == 0)
		len = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		arr[3];

	ft_index(arr);
	ptr = ffff(size, counts_z(size, strs, sep));
	if (!ptr)
		return (NULL);
	while (arr[0] < size)
	{
		while (strs[arr[0]][arr[1]])
		{
			ptr[arr[2]] = strs[arr[0]][arr[1]];
			increment(&arr[1], &arr[2]);
		}
		arr[1] = 0;
		while (sep[arr[1]] && size - arr[0] > 1)
		{
			ptr[arr[2]] = sep[arr[1]];
			increment(&arr[1], &arr[2]);
		}
		arr[1] = 0;
		arr[0]++;
	}
	ptr[arr[2]] = '\0';
	return (ptr);
}
/*int main()
{
	char *x;
	char *c[] = {"ahmad","hjh","efji"};
	char sep[] = " ";
	x =ft_strjoin(3, c,sep); 
	int i  =0;
	while (x[i])
	{
		write(1, &x[i], 1);
		i++;
	}
}*/
