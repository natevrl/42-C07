void	ft_swap3(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

void	ft_rev_int_tab(char	*tab)
{
	int	a;
    int max = ft_strlen(tab);
	a = 0;
	while (size != a + 1 && size != a)
	{
		ft_swap3(&tab[a], &tab[size - 1]);
		size--;
		a++;
	}
}




int check_base(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '-' || str[i] == '+' || str[i] == ' ' 
                || (str[i] >= 9 && str[i] <= 13))
            return (0);    
        i++;
    }
    return (1);
}

int    convert_in_decimal(char *str, char *base)
{
    long int    i;
    long int    res;
    long int    compteur_negatif;

    i = 0;
    res = 0;
    neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
    while ((str[i] == '-' || str[*i] == '+'))
	{
		if (str[i] == '-')
			compteur_negatif *= -1;
		i++;
    while (str[i] )
    {
        res = res * ft_strlen(base) + get_i_base(str[i], base);
        i++;
    }
    return res * compteur_negatif;
}


void	init_var(int	*i, int	*result,
		int	*convert_negativ, int	*compteur_negatif)
{
	*i = 0;
	*result = 0;
	*convert_negativ = 1;
	*compteur_negatif = 0;
}

void	boucle(char	*str, int	*i, int	*compteur_negatif)
{

	}
}

int	ft_atoi(char	*str)
{
	int	result;
	int	i;
	int	convert_negativ;
	int	compteur_negatif;

	init_var(&i, &result, &convert_negativ, &compteur_negatif);

	boucle(str, &i, &compteur_negatif);
	if (compteur_negatif % 2 == 1)
		convert_negativ = -1;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			result = result * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	if (result)
		return (convert_negativ * result);
	return (0);
}


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


int	get_index_of_number_base(char	n, char	*base)
{
    int i = 0;
    while (base[i])
    {
        if (n == base[i])
            return (i);
        i++;
    }
    return (-1);
}


int convert_in_decimal(char *nbr, char *base)
{
    int result;
    int i = 0;
    int len_base = ft_strlen(base);
    int convert_negativ = 1;

    if (nbr[0] == '-')
    {
        convert_negativ = -1;
        i++;
    }
    while (nbr[i])
    {
        result = result * len_base + get_index_of_number_base(nbr[i], base);
        i++;

    }
    return (convert_negativ * result);
}


#include <stdio.h>

int main()
{
    printf("%d", ft_lennumbers(-1234567890));
}
