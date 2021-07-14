/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:40:43 by nbenhado          #+#    #+#             */
/*   Updated: 2021/07/14 12:11:04 by nbenhado         ###   ########.fr       */
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

int is_in_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char *ft_split_copy(char *str, int fin, int debut)
{
	int taille;
	int	i = 0;
	taille = fin - debut;
	char *tab;

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

char  **test(char *str, char *charset)
{
	int i = 0;
	int j;
	int f = 0;
	int before_charset;
	int charset_end = 0;
	char **tab_de_tab;

	tab_de_tab = malloc(1000 * sizeof(char *));
	if (!tab_de_tab)
		return (NULL);
	while (str[i])
	{
		if (i == ft_strlen(str) - 1)
			tab_de_tab[f] = ft_split_copy(str, i + 1, charset_end);
		if (is_in_charset(str[i], charset))
		{
			j = 0;
			while (is_in_charset(str[i], charset))
			{
				i++;
				j++;
			}
			before_charset = i - j; // str avant de renconter un charset (fin a copier)
			tab_de_tab[f] = ft_split_copy(str, before_charset, charset_end);
			f++;
			charset_end = i; // fin du charset (debut de la nouvelle str a copier)
			i--;
		}
		i++;
	}
	tab_de_tab[f+1] = 0;
	return (tab_de_tab);
}

int main()
{
	char **tab;

	tab = test("  1 1    1 1         ", "1");

	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
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
