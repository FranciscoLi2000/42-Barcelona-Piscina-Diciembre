/*
 * •	Modificar argumentos directamente
 * •	Gestión de estados intermedios
 */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	/** store division result temporarily */
	temp = *a / *b;
	/** store remainder */
	*b = *a % *b;
	/** overwrite a with division result */
	*a = temp;
}
