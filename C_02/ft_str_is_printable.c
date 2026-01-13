int	ft_str_is_printable(char *str)
{
	unsigned int	i;
	unsigned char			c;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (c < 32 || c > 126)
			return (0);
		i++;
	}
	return (1);
}
