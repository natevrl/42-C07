/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:50:22 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/13 23:24:30 by nbenhado         ###   ########.fr       */
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

void	ft_swap(char	*a, char	*b)
{
	char	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_rev_int_tab(char	*tab)
{
	long int	a;
	long int	max;

	max = ft_strlen(tab);
	a = 0;
	while (max != a + 1 && max != a)
	{
		ft_swap(&tab[a], &tab[max - 1]);
		max--;
		a++;
	}
}

long int	convert_in_decimal(char	*str, char	*base)
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

char	*convert_nbr_base(long int	nbr, char	*base,
		char	*tab_malloc, long int	j)
{
	long int	lenchain;

	lenchain = ft_strlen(base);
	if (nbr > lenchain)
	{
		convert_nbr_base(nbr / lenchain, base, tab_malloc, j + 1);
		nbr = nbr % lenchain;
	}
	tab_malloc[j] = base[nbr];
	return (tab_malloc);
}

char	*ft_convert_base(char	*nbr, char	*base_from, char	*base_to)
{
	char		*tab;
	long int	testnb;
	char		*convert_nbr;

	if (!(check_base(base_from)) || !(check_base(base_to)))
		return (NULL);
	testnb = convert_in_decimal(nbr, base_from);
	if (testnb < 0)
	{
		testnb = -testnb;
		tab = malloc(100 * sizeof(char));
		if (!tab)
			return (NULL);
		convert_nbr = convert_nbr_base(testnb, base_to, tab, 1);
		tab[0] = '-';
		ft_rev_int_tab(convert_nbr + 1);
	}
	else
	{
		tab = malloc(100 * sizeof(char));
		if (!tab)
			return (NULL);
		convert_nbr = convert_nbr_base(testnb, base_to, tab, 0);
		ft_rev_int_tab(convert_nbr);
	}
	convert_nbr[ft_strlen(convert_nbr) + 1] = '\0';
	return (convert_nbr);
}

int	main(void)
{
printf("42:%s\n", ft_convert_base("qqqqwwweerr", "qwertyuio", "asdfghjkl"));
            printf("-42:%s\n", ft_convert_base("+----00042", "0123456789", "0123456789abcdef"));
            printf("2a:%s\n", ft_convert_base("42", "0123456789", "0123456789abcdef"));}
