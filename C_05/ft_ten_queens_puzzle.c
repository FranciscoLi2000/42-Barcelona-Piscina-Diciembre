#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col || board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

void	solve(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	printf("Solution = %d\n", ft_ten_queens_puzzle());
	return (0);
}
