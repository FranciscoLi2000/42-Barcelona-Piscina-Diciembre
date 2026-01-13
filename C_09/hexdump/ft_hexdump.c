/* hexdump parece magia negra, pero en realidad es puro orden + formato. Vamos paso a paso y luego te dejo un ft_hexdump -C totalmente funcional, nivel campus. */
/*
hexdump -C convierte bytes en algo humano-debuggeable.
Ejemplo:
echo "Hi" | hexdump -C
Salida:
00000000  48 69 0a                                       |Hi.|

Formato exacto de -C

Cada línea muestra 16 bytes:

OFFSET      HEXADECIMAL (16 bytes)              | ASCII |
00000000    xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx  |..............|
*/
/* Reglas clave:
 * •	Offset en hexadecimal, 8 caracteres
 * •	Hex:
 * •	16 bytes
 * •	espacio extra entre byte 8 y 9
 * •	ASCII:
 * •	imprimible → se muestra
 * •	no imprimible → .
 * •	Última línea puede tener menos de 16 bytes
 * •	Sin redirecciones (stdin o archivos directos)
 */
/* Estrategia mental (anti-miedo)
 *
 * Piensa así 🧠:
 * 1.	Lees 16 bytes
 * 2.	Imprimes offset
 * 3.	Imprimes hex (con padding)
 * 4.	Imprimes ASCII
 * 5.	Offset += bytes leídos
 * 6.	Repite hasta EOF
 */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 16

static void	print_error(const char *prog, const char *file)
{
	char	buf[512];
	int		n;

	n = snprintf(buf, sizeof(buf), "%s: %s: %s\n", prog, file, strerror(errno));
	write(2, buf, n);
}

static void	print_offset(unsigned int offset)
{
	char	hex[9];
	int		i;

	i = 7;
	hex[8] = '\0';
	while (i >= 0)
	{
		hex[i] = "0123456789abcdef"[offset % 16];
		offset /= 16;
		i--;
	}
	write(1, hex, 8);
	write(1, "  ", 2);
}

static void	print_hex(unsigned char *buf, int size)
{
	int		i;
	char	out[3];

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			out[0] = "0123456789abcdef"[buf[i] / 16];
			out[1] = "0123456789abcdef"[buf[i] % 16];
			out[2] = '\0';
			write(1, out, 2);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
}

static void	print_ascii(unsigned char *buf, int size)
{
	int	i;

	write(1, "|", 1);
	for (i = 0; i < size; i++)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, &buf[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "|\n", 2);
}

static void	hexdump_fd(int fd)
{
	unsigned char	buf[BUF_SIZE];
	ssize_t		r;
	unsigned int		offset;

	offset = 0;
	while ((r = read(fd, buf, BUF_SIZE)) > 0)
	{
		print_offset(offset);
		print_hex(buf, r);
		print_ascii(buf, r);
		offset += r;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;

	if (argc < 2 || strcmp(argv[1], "-C") != 0)
	{
		write(2, "Usage: ft_hexdump -C [file ...]\n", 32);
		return 1;
	}
	if (argc == 2)
	{
		hexdump_fd(0);
		return 0;
	}
	i = 2;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_error("ft_hexdump", argv[i]);
			i++;
			continue ;
		}
		hexdump_fd(fd);
		close(fd);
		i++;
	}
	return 0;
}
