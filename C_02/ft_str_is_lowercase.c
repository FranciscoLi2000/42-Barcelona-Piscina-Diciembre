int	ft_str_is_lowercase(char *str)
{
	unsigned int	i;
	char			c;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		c = str[i];
		if (!(c >= 'a' && c <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
