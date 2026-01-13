/*
 * Muestra en stdout el contenido del fichero pasado como único argumento.
 * Mensajes de error en stderr (salida reservada).
 * No se usa malloc; buffer fijo.
 */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 29696  /* un poco menos de 30 KB */

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	r;
	ssize_t	w;
	ssize_t	written;
	char	buf[BUF_SIZE];

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	while ((r = read(fd, buf, BUF_SIZE)) > 0)
	{
		written = 0;
		while (written < r)
		{
			w = write(1, buf + written, r - written);
			if (w < 0)
			{
				close(fd);
				write(2, "Cannot read file.\n", 18);
				return (1);
			}
			written += w;
		}
	}
	if (r < 0)
	{
		close(fd);
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	close(fd);
	return (0);
}
