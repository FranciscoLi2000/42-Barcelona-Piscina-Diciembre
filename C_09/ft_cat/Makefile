CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
SRCS = ft_cat.c

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
		@rm -f *.o

fclean: clean
		@rm -f $(NAME)

.PHONY: all clean fclean

# Notas importantes y consejos de testing
# •	Ambos programas no usan malloc. Buffer fijo BUF_SIZE = 29696 bytes (≈ 29 KB).
# •	Para probar límites de buffer con ulimit puedes limitar recursos en la shell. Ten en cuenta que distintas opciones de ulimit controlan cosas distintas (memoria virtual, tamaño de fichero, etc.). Un ejemplo para limitar tamaño máximo de fichero creado (en bloques de 512 bytes):
# •	ulimit -f 60  (esto limita archivos nuevos a ~30 KB = 60*512 bytes).
# Ajusta según lo que quieras comprobar.
# (Prueba tus casos: archivos grandes, lectura desde stdin con dd if=/dev/zero bs=1k count=50 | ./ft_cat > out etc.)
# •	Si quieres que ft_cat falle exactamente como la versión del campus (mensajes exactos), dime el formato que espera el juez y lo adapto.

