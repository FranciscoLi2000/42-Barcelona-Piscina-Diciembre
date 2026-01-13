char	*ft_strupcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (char)(str[i] - ('a' - 'A'));
		i++;
	}
	return (str);
}
