/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:32:57 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/16 16:00:24 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int		*ptr;
	int		c;

	c = max - min;
	if (min >= max)
	{
		ptr = NULL;
		return (ptr);
	}
	ptr = malloc((c) * sizeof(int));
	c = 0;
	if (!ptr)
		return (NULL);
	while (min < max)
	{
		ptr[c] = min;
		min++;
		c++;
	}
	return (ptr);
}
