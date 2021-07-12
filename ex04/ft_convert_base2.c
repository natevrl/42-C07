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
