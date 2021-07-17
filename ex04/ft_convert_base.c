/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:50:22 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/17 13:58:09 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			get_i_base(char	n, char	*base);
long int	ft_lennumbers(long int	nb);
long int	ft_strlen(char	*str);
int			check_base(char	*base);
int			is_in_base(char	n, char	*base);

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char	*dest, char	c)
{
	int	max;

	max = 0;
	while (dest[max] != '\0')
		max++;
	dest[max] = c;
	dest[max + 1] = '\0';
	return (dest);
}

long int	ft_atoi_base(char	*str, char	*base)
{
	long int	i;
	long int	res;
	long int	compteur_negatif;

	i = 0;
	res = 0;
	compteur_negatif = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			compteur_negatif *= -1;
		i++;
	}
	while (str[i] && is_in_base(str[i], base))
	{
		res = res * ft_strlen(base) + get_i_base(str[i], base);
		i++;
	}
	return (res * compteur_negatif);
}

void	ft_putnbr_base(long int	nbr, char	*base, char	*buffer)
{
	long int	lenchain;

	lenchain = ft_strlen(base);
	if (nbr < 0)
	{
		buffer[0] = '-';
		nbr = -nbr;
	}	
	if (nbr > lenchain - 1)
	{
		ft_putnbr_base(nbr / lenchain, base, buffer);
		nbr = nbr % lenchain;
	}
	ft_strcat(buffer, base[nbr]);
}

char	*ft_convert_base(char	*nbr, char	*base_from, char	*base_to)
{
	long int	var_atoi;
	char		buffer[128];

	if (!(check_base(base_from)) || !(check_base(base_to)))
		return (NULL);
	var_atoi = ft_atoi_base(nbr, base_from);
	buffer[0] = '\0';
	buffer[1] = '\0';
	ft_putnbr_base(var_atoi, base_to, buffer);
	return (ft_strdup(buffer));
}
