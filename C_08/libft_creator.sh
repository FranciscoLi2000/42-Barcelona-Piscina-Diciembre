# Primero: el script — cuando ejecutes sh libft_creator.sh construirá la librería (usa make internamente, así la prueba puede usar solo el Makefile).

# Luego el Makefile (sin wildcards, .o junto a sus .c en srcs/, flags en el orden que pides, reglas all, libft.a, clean, fclean, re). Todo lo que imprime make son las líneas ejecutadas (no escondo comandos).

# Copia exactamente estos dos ficheros al root del ejercicio.

#!/bin/sh
# tiny wrapper: build libft.a using the Makefile
# prints commands (set -x) so CI/users can see what's happening
set -eu
echo "Running libft_creator.sh -> delegating to make"
# show commands as they run
set -x
make

# Hazlo ejecutable si quieres: chmod +x libft_creator.sh (no obligatorio; sh libft_creator.sh funciona).

