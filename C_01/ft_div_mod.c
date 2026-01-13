/*
 * •	Devolver múltiples valores usando punteros
 * •	División entera y módulo
 */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	/** integer division */
	*div = a / b;
	/** remainder of the division */
	*mod = a % b;
}
