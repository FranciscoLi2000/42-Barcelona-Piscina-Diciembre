/*
 * Aquí pasa algo distinto
 * •	La función asigna memoria
 * Pero NO devuelve el puntero, lo mete en *range
 * Responsabilidades
 * •	La función:
 * •	hace malloc
 * •	asigna *range
 * •	El caller:
 * •	hace free(*range)
 * Valores de retorno:
 * •	-1 → error de malloc
 * •	0 → rango vacío (*range = NULL)
 * •	>0 → tamaño del array
 * Frase mental: “Aunque no devuelva el puntero, alguien tiene que liberarlo → el caller”
 */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (i);
}
