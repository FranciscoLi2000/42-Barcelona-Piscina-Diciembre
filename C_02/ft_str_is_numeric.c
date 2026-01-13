int	ft_str_is_numeric(char *str)
{
	unsigned int	i;
	char			c;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		c = str[i];
		if (!(c >= '0' && c <= '9'))
			return (0);
		i++;
	}
	return (1);
}
