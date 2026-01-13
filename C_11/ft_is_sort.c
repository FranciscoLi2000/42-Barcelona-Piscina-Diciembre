/* ft_is_sort.c */
#include "ft.h"

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;
	int	r;

	if (!tab || length < 2 || !f)
		return 1;
	asc = 1;
	desc = 1;
	i = 0;
	while (i < length - 1)
	{
		r = f(tab[i], tab[i + 1]);
		if (r > 0) /* tab[i] > tab[i+1] */
			asc = 0;
		if (r < 0) /* tab[i] < tab[i+1] */
			desc = 0;
		i++;
	}
	return (asc || desc) ? 1 : 0;
}
