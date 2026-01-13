/*
 * •	Qué es realmente la longitud de un string
 * •	Contar memoria hasta \0
 */

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
