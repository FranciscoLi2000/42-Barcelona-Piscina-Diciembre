/*
 * •	Reserva memoria nueva
 * •	Copia src
 * •	Devuelve un char *
 *
 * Memory mindset
 * •	malloc dentro ✅
 * •	free ❌ (lo hará el que llame)
 *
 * Frase para recordarlo: “Si devuelvo un puntero nuevo → alguien tendrá que liberarlo”
 */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
