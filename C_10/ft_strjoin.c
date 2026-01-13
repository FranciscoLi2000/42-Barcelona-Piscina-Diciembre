/*
 * •	Crea una string nueva
 * •	Incluso si size == 0
 *
 * Memory mindset
 * •	Siempre devuelve algo freeable
 * •	malloc inside
 * •	free outside
 * 
 * Ojo:
 * char	*s = ft_strjoin(0, strs, sep);
 * free(s); SIEMPRE
 */

#include <stdlib.h>

static void	ft_strcpy(char *dst, char *src, int *pos)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dst[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		pos;
	int		total;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char));
		if (res)
			res[0] = '\0';
		return (res);
	}
	total = 0;
	i = -1;
	while (++i < size)
		total += ft_strlen(strs[i]);
	total += ft_strlen(sep) * (size - 1);
	res = (char *)malloc(sizeof(char) * (total + 1));
	if (!res)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_strcpy(res, strs[i], &pos);
		if (i++ < size - 1)
			ft_strcpy(res, sep, &pos);
	}
	res[pos] = '\0';
	return (res);
}
