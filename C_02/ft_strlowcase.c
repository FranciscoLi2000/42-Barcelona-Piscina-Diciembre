char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (char)(str[i] + ('a' - 'A'));
		i++;
	}
	return (str);
}
