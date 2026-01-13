/*
 * •	Recursion + backtracking
 * •	Arrays
 * •	Generalized combinations
 * •	Advanced loop logic 🧠💥
 */

void	print_number(int *arr, int n, int is_last)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
	if (!is_last)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	backtrack(int *arr, int index, int n, int start)
{
	int		i;

	if (index == n)
	{
		print_number(arr, n, arr[0] == 10 - n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		arr[index] = i;
		backtrack(arr, index + 1, n, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		arr[10];

	if (n < 1 || n > 9)
		return ;
	backtrack(arr, 0, n, 0);
}
