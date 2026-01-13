/* Similar a ft_atoi, pero:
 * •	Base custom
 * •	Convertimos según el índice del carácter en la base
 * •	Si base es inválida → return 0
 */

static int	base_index(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		result;
	int		b_index;

	if (!is_valid_base(base))
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((b_index = base_index(str[i], base)) != -1)
	{
		result = result * ft_strlen(base) + b_index;
		i++;
	}
	return (result * sign);
}
