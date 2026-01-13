/* ft_foreach.c */
#include "ft.h"

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	if (!tab || length <= 0 || !f)
		return ;
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
