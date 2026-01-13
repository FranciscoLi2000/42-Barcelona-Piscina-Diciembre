/* --------- capitalize --------- */
/* A word is a sequence of alphanumeric characters. */
char	*ft_strcapitalize(char *str)
{
	unsigned int		i;
	unsigned char	cur;
	unsigned char	p;
	int			is_alnum;
	int			prev_is_alnum;

	i = 0;
	if (!str)
		return (str);
	/* first make all lowercase */
	ft_strlowcase(str);
	while (str[i])
	{
		cur = (unsigned char)str[i];
		is_alnum = ((cur >= 'a' && cur <= 'z') || (cur >= 'A' && cur <= 'Z') || (cur >= '0' && cur <= '9'));
		prev_is_alnum = 0;
		if (i > 0)
		{
			p = (unsigned char)str[i - 1];
			prev_is_alnum = ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z') || (p >= '0' && p <= '9'));
		}
		if (is_alnum && !prev_is_alnum)
		{
			/* start of a word -> if letter, uppercase it */
			if (cur >= 'a' && cur <= 'z')
				str[i] = (char)(cur - ('a' - 'A'));
		}
		i++;
	}
	return (str);
}
