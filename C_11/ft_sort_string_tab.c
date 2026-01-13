/* ft_sort_string_tab.c */
#include "ft.h"
#include <string.h>

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j + 1])
		{
			if (strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
