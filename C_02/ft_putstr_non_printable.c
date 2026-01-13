/* --------- putstr non printable (hex lowercase with backslash) --------- */
static void	write_char(char c)
{
	write(1, &c, 1);
}

static void	write_buf(const char *buf, unsigned long len)
{
	write(1, buf, len);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int		i;
	unsigned char	c;
	char		hex[2];
	char		out[3];
	const char	*hexmap = "0123456789abcdef";

	i = 0;
	while (str && str[i])
	{
		c = (unsigned char)str[i];
		if (c >= 32 && c <= 126)
			write_char((char)c);
		else
		{
			out[0] = '\\';
			out[1] = hexmap[c / 16];
			out[2] = hexmap[c % 16];
			write_buf(out, 3);
		}
		i++;
	}
}
