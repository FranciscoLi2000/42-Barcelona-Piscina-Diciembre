# Nota rápida sobre cómo usarlo
#	Estructura esperada:

#/ (root)
#├── Makefile
#├── libft_creator.sh
#├── includes/ft.h
#├── srcs/*.c

#	Ejecuta make o sh libft_creator.sh. make crea libft.a en el root.
#	make clean borra .o, make fclean además borra libft.a, make re rebuild total.

# Diferencia entre librería estática y dinámica (short & chill)
# •	Estática (.a):
# •	Linkada en compilación. El código que usas se copia dentro del ejecutable.
# •	Ventajas: ejecutable autónomo, no dependes de librerías en runtime.
# •	Contras: binario más grande; si actualizas la librería hay que recompilar los ejecutables.
# •	Dinámica (.so / .dylib / .dll):
# •	Linkada en tiempo de ejecución (o al arrancar). El ejecutable referencia la librería externa.
# •	Ventajas: ejecutables más pequeños; puedes actualizar la librería sin recompilar los binarios.
# •	Contras: dependencias en runtime (si falta la .so la app falla); versiones y símbolos pueden romper compatibilidad.

# En resumen: usa .a para cosas simples o cuando quieras un binario independiente; usa .so para compartir código entre muchos programas o cuando quieras hot-fixes sin recompilar.

# Minimal libft Makefile (no wildcards, .o next to .c in srcs/)
# Default goal = all
.DEFAULT_GOAL := all

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar
ARFLAGS		= rcs
RM		= rm -f

INCLUDES_DIR	= includes

SRCS		= srcs/*.c

OBJS		= srcs/*.o

LIB		= libft.a

# by default build the library
all: $(LIB)

# create library from object files
# this rule only runs the link/archive command when an object changed
$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $(LIB) $(OBJS)

# compile .c -> .o placing .o next to .c (srcs/)
# each object depends on its source and headers
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

# remove temporary object files
clean:
	$(RM) $(OBJS)

# remove objects and the library
fclean: clean
	$(RM) $(LIB)

# rebuild everything
re: fclean all

.PHONY: all clean fclean re
