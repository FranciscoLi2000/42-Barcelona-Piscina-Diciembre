/* 
 * (implementa struct s_stock_str *ft_strs_to_tab(int ac, char **av);)
 */

#include <stdlib.h>
#include "ft_stock_str.h"

/* helpers */
static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int				i;
	int				j;

	if (ac < 0)
		ac = 0;
	arr = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		if (arr[i].copy == NULL)
		{
			/* cleanup on failure */
			j = 0;
			while (j < i)
			{
				free(arr[j].copy);
				j++;
			}
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i].str = 0; /* mark end */
	arr[i].copy = 0;
	arr[i].size = 0;
	return (arr);
}
