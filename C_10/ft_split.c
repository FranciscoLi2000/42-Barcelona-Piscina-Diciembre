/* Aquí hay doble nivel de memoria:
 * 1.	Array de punteros (char **)
 * 2.	Cada palabra (char *)
 *
 * Lo que reservas:
 * [ char* ] -> palabra 1
 * [ char* ] -> palabra 2
 * [ char* ] -> palabra 3
 * [  NULL  ]
 *
 * Cómo se libera:
 * int i = 0;
 * while (split[i])
 * {
 * 	free(split[i]);
 * 	i++;
 * }
 * free(split);
 *
 * Regla mental: Si hay un array de punteros → tengo que liberar en dos niveles
 */

#include <stdlib.h>

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (1);
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

static char	*word_dup(char *str, char *charset)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			res[i] = word_dup(str, charset);
			if (!res[i])
				return (NULL);
			i++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	res[i] = NULL;
	return (res);
}
