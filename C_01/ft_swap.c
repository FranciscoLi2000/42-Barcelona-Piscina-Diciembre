/*
 * •	Paso por referencia
 * •	Uso de variable temporal
 * •	Manipulación directa de memoria
 */

void	ft_swap(int *a, int *b)
{
	int	temp;

	/* classic swap using a temporary variable */
	temp = *a;
	*a = *b;
	*b = temp;
}
