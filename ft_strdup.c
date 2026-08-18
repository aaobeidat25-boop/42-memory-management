/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:25:24 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/17 15:01:27 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		x++;
		i++;
	}
	ptr = malloc((x + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[x] = '\0';
	return (ptr);
}
