/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:39:00 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/17 13:54:59 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

long int	ft_atoi_base(char *str, char *base);
char		*ft_putnbr_base(long int	nbr, char	*base,
				char	*tab_malloc, long int	j);
char		*ft_convert_base(char	*nbr, char	*base_from, char	*base_to);

long int	ft_lennumbers(long int nb)
{
	long int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

long int	ft_strlen(char	*str)
{
	long int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	check_base(char	*base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_in_base(char	n, char	*base)
{
	long int	i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (base[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	get_i_base(char	n, char	*base)
{
	long int	i;

	i = 0;
	while (i < ft_strlen(base))
	{
		if (base[i] == n)
			return (i);
		i++;
	}
	return (-1);
}
