/*
 * •	Strings en C (char *)
 * •	Fin de string con \0
 * •	Iteración por memoria
 */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	/* iterate until null terminator */
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
