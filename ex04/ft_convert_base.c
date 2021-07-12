/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:50:22 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/12 23:50:05 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_lennumbers(int nb)
{
    int i = 0;
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


void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	ft_strlen(char	*str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}


int    get_i_base(char n, char *base)
{
    int    i;

    i = 0;
    while (i < ft_strlen(base))
    {
        if (base[i] == n)
            return (i);
        i++;
    }
    return (-1);
}

int    convert_in_decimal(char *str, char *base)
{
    int    i;
    int    res;
    int    neg;

    i = 0;
    res = 0;
    neg = 1;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        res = res * ft_strlen(base) + get_i_base(str[i], base);
        i++;
    }
    return res;
}


void	ft_swap3(char *a, char *b)
{
	char	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_rev_int_tab(char	*tab)
{
	int	a;
    int max = ft_strlen(tab);
	a = 0;
	while (max != a + 1 && max != a)
	{
		ft_swap3(&tab[a], &tab[max - 1]);
		max--;
		a++;
	}
}

char    *convert_nbr_base(int nbr, char *base, char *tab_malloc, long int   j)
{
    long int lenchain;

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
    char *tab;
    unsigned int testnb;
    char *lol;
    testnb  = convert_in_decimal(nbr, base_from);
    printf("%d\n", testnb);
    if (nbr[0] == '-')
    {
        tab = malloc(ft_lennumbers(testnb)  * sizeof(char) + 1);
        lol = convert_nbr_base(testnb, base_to, tab, 1);
        ft_rev_int_tab(lol);
        tab[0] = '-';
    }
    else
    {
        tab = malloc(ft_lennumbers(testnb) * sizeof(char));
        lol = convert_nbr_base(testnb, base_to, tab, 0);
        ft_rev_int_tab(lol);
    }
    return (lol);
}


int	main(void)
{
    
    printf("2a:%s\n", ft_convert_base("-420", "0123456789", "0123456789abcdef"));
    printf("42:%s\n", ft_convert_base("-vn", "poneyvif", "0123456789"));
    printf("42:%s\n", ft_convert_base("2a", "0123456789abcdef", "0123456789"));
}
