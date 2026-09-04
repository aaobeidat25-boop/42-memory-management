/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 09:23:34 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/18 14:59:53 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	isvalidlength(char *base);
int	getcharvalue(char c, char *base);
int	isvalidnbr(char *nbr, char *base);
int	isvalidbase(char *base);
int	countsigns(char *nbr, long *i);

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

long	conv_to_decimal(char *nbr, char *basefrom)
{
	long		i;
	long		radix;
	long		decimal;
	long		x;
	long		negg;

	i = 0;
	negg = countsigns(nbr, &i);
	decimal = 0;
	radix = 0;
	while (basefrom[radix])
		radix++;
	while (nbr[i])
	{
		x = getcharvalue(nbr[i], basefrom);
		decimal = decimal * radix + x;
		i++;
	}
	if (negg)
		decimal = -decimal;
	return (decimal);
}

long	countdigitofbaseto(char *nbr, char *base_from, char *base_to)
{
	long		k;
	long		i;
	long		j;

	k = 0;
	i = conv_to_decimal(nbr, base_from);
	if (i < 0)
		i = -i;
	j = 0;
	while (base_to[j])
	{
		j++;
	}
	while (i > 0)
	{
		k++;
		i /= j;
	}
	return (k);
}

void	putvaluesinptr(char *ptr, char *nbr, char *base_from, char *base_to)
{
	int		arr[5];

	array(arr);
	arr[0] = countdigitofbaseto(nbr, base_from, base_to);
	arr[1] = conv_to_decimal(nbr, base_from);
	arr[4] = 0;
	if (arr[1] < 0)
	{
		arr[4] = 1;
		arr[1] = -arr[1];
		ptr[0] = '-';
	}
	arr[2] = 0;
	arr[3] = 0;
	while (base_to[arr[3]])
	{
		arr[3]++;
	}
	while (arr[2] < arr[0])
	{
		ptr[arr[4] + arr[0] - arr[2] - 1] = base_to[arr[1] % arr[3]];
		arr[1] /= arr[3];
		arr[2]++;
	}
	ptr[arr[4] + arr[0]] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char*base_to)
{
	long	i;
	char	*ptr;

	i = 0;
	if (isvalidlength(base_from) && isvalidnbr(nbr, base_from)
		&&isvalidbase(base_from) && isvalidbase(base_to))
	{
		while (nbr[i] == '-' || nbr[i] == '+')
			i++;
		while (nbr[i])
		{
			if (getcharvalue(nbr[i], base_from) == -1)
			{
				return (NULL);
			}
			i++;
		}
		ptr = malloc((countdigitofbaseto(nbr, base_from, base_to)
					+(conv_to_decimal(nbr, base_from) < 0) + 1));
		if (!ptr)
			return (NULL);
		putvaluesinptr(ptr, nbr, base_from, base_to);
		return (ptr);
	}
	return (NULL);
}
/*int main()
{
	char nbr[] = "-1499591369";
	char basefrom[] = "0123456789";
	char baseto[] = "01";
	char *x;
	x = ft_convert_base(nbr, basefrom, baseto);
	printf("%s",x);
}*/
