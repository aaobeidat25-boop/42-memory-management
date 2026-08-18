/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahobeida <ahobeida@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:33:46 by ahobeida          #+#    #+#             */
/*   Updated: 2026/08/18 14:46:54 by ahobeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isvalidlength(char *base)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (base[i])
	{
		i++;
	}
	while (base[j])
	{
		if (base[j] == '-' || base[j] == '+' || base[j] == ' '
			|| (base[j] >= 9 && base[j] <= 13))
		{
			i = 0;
		}
		j++;
	}
	return (i);
}

long	countsigns(char *nbr, long *i)
{
	long		negg;

	negg = 0;
	while (nbr[*i] == '-' || nbr[*i] == '+')
	{
		if (nbr[*i] == '-')
			negg++;
		(*i)++;
	}
	return (negg % 2);
}

int	getcharvalue(char c, char *base)
{
	int		i;

	i = 0;
	if (c == '-' || c == '+')
		i++;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	isvalidnbr(char *nbr, char *base)
{
	int		i;

	i = 0;
	while (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!nbr[i])
		return (0);
	while (nbr[i])
	{
		if (getcharvalue(nbr[i], base) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	isvalidbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (isvalidlength(base) < 2)
	{
		return (0);
	}
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
