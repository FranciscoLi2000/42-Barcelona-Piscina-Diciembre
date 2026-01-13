/*
 * •	Function declaration
 * •	char type
 * •	System call write (low-level output, Unix vibes)
 */

#include <unistd.h>

void	ft_putchar(char c)
{
	/* write writes raw bytes directly to stdout (fd = 1) */
	write(1, &c, 1);
}
