/* ft_map.c */
#include "ft.h"
#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*res;
	int	i;

	if (!tab || length <= 0 || !f)
		return (NULL);
	res = (int*)malloc(sizeof(int) * (size_t)length);
	if (!res)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
