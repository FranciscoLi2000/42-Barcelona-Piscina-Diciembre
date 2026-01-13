/*
 * •	Loops (while)
 * •	ASCII ordering
 * •	Reusing functions (modularity)
 */

void	ft_print_alphabet(void)
{
	char	c;

	/** characters are stored as ASCII values */
	c = 'a';
	while (c <= 'z')
	{
		ft_putchar(c);
		c++;
	}
}
