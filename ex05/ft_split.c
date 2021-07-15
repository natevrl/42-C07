/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:40:43 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/15 17:02:53 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_split_copy(char *str, int fin, int debut)
{
	int		taille;
	int		i;
	char	*tab;

	i = 0;
	taille = fin - debut;
	tab = malloc(taille * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	while (debut < fin)
	{
		tab[i] = str[debut];
		debut++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

void	init_var(int *i, int *f, int *charset_end)
{
	*i = 0;
	*f = 0;
	*charset_end = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		f;
	int		charset_end;
	char	**tab_de_tab;

	init_var(&i, &f, &charset_end);
	tab_de_tab = malloc(100 * sizeof(char *));
	if (!tab_de_tab)
		return (NULL);
	while (str[++i])
	{
		if (i == ft_strlen(str) - 1)
			tab_de_tab[f] = ft_split_copy(str, i + 1, charset_end);
		j = 0;
		if (is_in_charset(str[i], charset))
		{
			while (is_in_charset(str[++i], charset))
				j++;
			tab_de_tab[f++] = ft_split_copy(str, (i - 1) - j, charset_end);
			charset_end = i--;
		}
	}
	tab_de_tab[f + 1] = 0;
	return (tab_de_tab);
}

int main()
{
	char **tab;
	tab = ft_split("a12vadaw23awd2daw213awd112233awd22 ", "123");

	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
	printf("%s\n", tab[5]);
	printf("%s\n", tab[6]);
	printf("%s\n", tab[7]);
}
/*
#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);


int	main(void)
{
char s1a[] = "1,,,2,,,3,,,4,5,6";
char s2a[] = ",,,";

printf("%s\n", ft_strstr(s1a, s2a));
int		main(void)
{
char **tab;

//	tab = ft_split("Ceci&est$un##############################################################################################################################################################succes@!", "&$#@");
}
}*/
