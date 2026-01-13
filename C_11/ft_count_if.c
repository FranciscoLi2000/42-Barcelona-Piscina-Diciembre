/* ft_count_if.c */
#include "ft.h"

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	cnt;

	if (!tab || length <= 0 || !f)
		return 0;
	cnt = 0;
	i = 0;
	while (i < length)
	{
		if (tab[i] && f(tab[i]) != 0)
			cnt++;
		i++;
	}
	return cnt;
}
