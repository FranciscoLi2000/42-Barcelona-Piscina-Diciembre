/*
 * El comando tail imprime las últimas líneas o bytes de un archivo.
 * Ejemplos reales:
 * tail file.txt        # últimas 10 líneas
 * tail -c 20 file.txt  # últimos 20 bytes
 *
 * En tu ejercicio SOLO importa:
 * tail -c N archivo
 * 
 * •	-c N = muestra los últimos N bytes
 * •	No necesitas manejar + o -
 * •	Todos los tests usan -c
 * •	Puedes usar errno
 * •	❌ malloc prohibido
 * •	✅ buffer fijo
 */
/*
 * Estrategia mental (modo hacker 🧠)
 *
 * Para tail -c hay dos formas:
 *
 * Método pro (el que espera el ejercicio)
 * 1.	Abres el archivo
 * 2.	Vas al final con lseek
 * 3.	Retrocedes N bytes
 * 4.	Lees desde ahí hasta el final
 * 5.	Escribes en stdout
 *
 * 💡 Si el archivo es más pequeño que N, imprimes todo.
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 29696

static void	print_error(const char *prog, const char *file)
{
	char	buf[512];
	int		n;

	n = snprintf(buf, sizeof(buf), "%s: %s: %s\n", prog, file, strerror(errno));
	write(2, buf, n);
}

static int	ft_atoi(char *s)
{
	int	n;

	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return n;
}

int	main(int argc, char **argv)
{
	int		fd;
	int		count;
	off_t	size;
	off_t	start;
	char	buf[BUF_SIZE];
	ssize_t	r;

	if (argc != 4 || strcmp(argv[1], "-c") != 0)
	{
		write(2, "Usage: ft_tail -c number file\n", 30);
		return 1;
	}
	count = ft_atoi(argv[2]);
	fd = open(argv[3], O_RDONLY);
	if (fd < 0)
	{
		print_error("ft_tail", argv[3]);
		return 1;
	}
	size = lseek(fd, 0, SEEK_END);
	if (size < 0)
	{
		print_error("ft_tail", argv[3]);
		close(fd);
		return 1;
	}
	start = size - count;
	if (start < 0)
		start = 0;
	lseek(fd, start, SEEK_SET);
	while ((r = read(fd, buf, BUF_SIZE)) > 0)
		write(1, buf, r);
	if (r < 0)
		print_error("ft_tail", argv[3]);
	close(fd);
	return 0;
}
