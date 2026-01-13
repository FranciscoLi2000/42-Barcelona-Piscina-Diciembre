/* --------- print_memory --------- */
static void	print_hex_byte(unsigned char b)
{
	const char	*hexmap = "0123456789abcdef";
	char		out[2];

	out[0] = hexmap[b / 16];
	out[1] = hexmap[b % 16];
	write_buf(out, 2);
}

static void	print_addr_hex(uintptr_t addr)
{
	const char	*hexmap = "0123456789abcdef";
	char		buf[16];
	int			i;

	i = 15;
	while (i >= 0)
	{
		buf[i] = hexmap[addr % 16];
		addr /= 16;
		--i;
	}
	write_buf(buf, 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*p;
	unsigned int		i;
	unsigned int		j;

	if (size == 0)
		return (addr);
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		/* address */
		print_addr_hex((uintptr_t)(p + i));
		write_char(':');
		write_char(' ');
		/* hex content: 16 bytes per line, group every 2 bytes with a space */
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
				print_hex_byte(p[i + j]);
			else
			{
				write_char(' ');
				write_char(' ');
			}
			if (j % 2 == 1)
				write_char(' ');
			j++;
		}
		/* printable chars */
		for (unsigned int j = 0; j < 16; j++)
		{
			if (i + j < size)
			{
				unsigned char	c = p[i + j];
				if (c >= 32 && c <= 126)
					write_char((char)c);
				else
					write_char('.');
			}
		}
		write_char('\n');
		i += 16;
	}
	return (addr);
}
