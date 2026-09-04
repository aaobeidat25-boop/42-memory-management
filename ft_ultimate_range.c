/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:42:32 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/16 16:40:43 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		diff;
	int		i;

	diff = max - min;
	i = 0;
	if (min >= max)
	{
		*(range) = NULL;
		return (0);
	}
	*(range) = malloc((diff) * sizeof(int));
	if (!(*range))
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (diff);
}
/*int main()
{
	int *range;
	int mn = 0;
	int mx = 5;
	int x;
	x = ft_ultimate_range(&range , mn, mx);
	printf("%d", x);
	printf("%d\n",5);
	
	int i =0;
	while (i < x)
	{
		printf("%d", range[i]);
		i++;
	}
}*/
