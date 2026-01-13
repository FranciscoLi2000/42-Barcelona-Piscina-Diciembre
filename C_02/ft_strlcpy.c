/* --------- strlcpy --------- */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		src_len;
	unsigned int		to_copy;
	unsigned int		i;

	src_len = ft_strlen(src);
	to_copy = 0;
	if (size > 0)
	{
		if (src_len >= size)
			to_copy = size - 1;
		else
			to_copy = src_len;
		i = 0;
		while (i < to_copy)
		{
			dest[i] = src[i];
			i++;
		}
		dest[to_copy] = '\0';
	}
	return (src_len);
}
