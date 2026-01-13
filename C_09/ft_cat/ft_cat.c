/* 
 * Comportamiento similar a cat (sin opciones). Si no recibe argumentos, lee de stdin; si recibe ficheros, los muestra en orden. Mensajes de error incluyen errno (ej.: "ft_cat: nombre: <mensaje error>\n"). Buffer fijo.
 */
/*
 * Minimal cat: si no hay argumentos lee stdin, si hay archivos los imprime en orden.
 * Usa errno para formar el mensaje de error.
 * Buffer fijo (menor que 30 KB).
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 29696  /* un poco menos de 30 KB */

static void	print_err_file(const char *prog, const char *fname)
{
	char	errbuf[512];
	int		n;

	/* snprintf seguro para formar: prog: fname: strerror(errno)\n */
	n = snprintf(errbuf, sizeof(errbuf), "%s: %s: %s\n", prog, fname, strerror(errno));
	if (n > 0)
		write(2, errbuf, (n < (int)sizeof(errbuf)) ? n : (int)sizeof(errbuf));
}

static int	do_fd_to_stdout(int fd)
{
	char	buf[BUF_SIZE];
	ssize_t	r;
	ssize_t	w;
	ssize_t	written;

	while ((r = read(fd, buf, BUF_SIZE)) > 0)
	{
		written = 0;
		while (written < r)
		{
			w = write(1, buf + written, r - written);
			if (w < 0)
				return -1;
			written += w;
		}
	}
	if (r < 0)
		return -1;
	return 0;
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
	{
		/* leer stdin */
		if (do_fd_to_stdout(0) < 0)
		{
			/* mensaje genérico si lectura de stdin falla */
			write(2, "ft_cat: error reading stdin\n", 28);
			return 1;
		}
		return 0;
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_err_file("ft_cat", argv[i]);
			/* seguir con siguientes archivos (comportamiento típico de cat) */
			continue ;
		}
		if (do_fd_to_stdout(fd) < 0)
		{
			print_err_file("ft_cat", argv[i]);
			close(fd);
			continue ;
		}
		close(fd);
	}
	return 0;
}
