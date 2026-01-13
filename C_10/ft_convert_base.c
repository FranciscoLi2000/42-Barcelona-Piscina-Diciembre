/* Cosas importantes:
 * •	Devuelve una string nueva
 * •	Puede devolver NULL
 *
 * Memory:
 * •	malloc dentro
 * •	free fuera
 * •	Si devuelve NULL, no se libera nada
 */

#include <stdlib.h>

static int	base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i >= 2 ? i : 0);
}

static int	in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	res;
	int	b;

	b = base_len(base);
	if (!b)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	res = 0;
	while (in_base(*str, base) != -1)
	{
		res = res * b + in_base(*str, base);
		str++;
	}
	return (res * sign);
}

static char	*ft_putnbr_base(int nbr, char *base)
{
	char	buf[35];
	int		b;
	int		i;
	long	n;

	b = base_len(base);
	n = nbr;
	i = 34;
	buf[i--] = '\0';
	if (n == 0)
		buf[i--] = base[0];
	if (n < 0)
		n = -n;
	while (n)
	{
		buf[i--] = base[n % b];
		n /= b;
	}
	if (nbr < 0)
		buf[i--] = '-';
	return (ft_strdup(&buf[i + 1]));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!base_len(base_from) || !base_len(base_to))
		return (NULL);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}
