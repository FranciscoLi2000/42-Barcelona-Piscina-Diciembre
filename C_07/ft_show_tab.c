/*
 * (implementa void ft_show_tab(struct s_stock_str *par); — imprime cada elemento en el formato pedido)
 */

#include <unistd.h>
#include "ft_stock_str.h"

static void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	long	num;
	char		c;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	c = (char)('0' + (num % 10));
	ft_putchar(c);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (!par)
		return ;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

/*
 * Cómo compilar / pruebas
 *
 * 1.	Para probar el ft_boolean main que diste, crea main.c con el contenido que pusiste, y compila:
 * gcc -Wall -Wextra -Werror main.c ft_boolean.h ft_basic.c -o test_bool
 * (Nota: ft_basic.c no es necesario si tu main define ft_putstr localmente, como en el ejemplo.)
 *
 * 2.	Para probar ft_strs_to_tab y ft_show_tab, compila:
 * gcc -Wall -Wextra -Werror ft_strs_to_tab.c ft_show_tab.c ft_basic.c -o showtab
 * y en main.c puedes usar:
 */
#include "ft_stock_str.h"

int	main(int argc, char **argv)
{
	struct s_stock_str	*arr = ft_strs_to_tab(argc, argv);

	ft_show_tab(arr);
	/* free memory allocated by ft_strs_to_tab */
	for (int i = 0; i < argc; ++i)
		free(arr[i].copy);
	free(arr);
	return (0);
}
