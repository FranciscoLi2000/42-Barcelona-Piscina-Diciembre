/* --------- strstr --------- */
/* finds first occurrence of to_find in str */
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	if (!to_find[0])
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return (&str[i]);
		i++;
	}
	return (0);
}
