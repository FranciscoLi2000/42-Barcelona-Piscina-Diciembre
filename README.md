Para ese tipo de scripts no estás casado con un solo lenguaje. Piensa en esto como distintos levels de poder:

⸻

🐚 Shell (sh / bash / zsh)

El OG. El más usado para lo que estás haciendo.
•	Perfecto para: ls, find, sed, awk, pipes, permisos, Git, sistema.
•	Pros: cero dependencias, vive en el sistema.
•	Contras: sintaxis críptica a veces 💀

👉 Ideal para 42-style exercises y automatización directa.

⸻

🐍 Python

El “modo fácil pero elegante”.
•	Perfecto para: texto complejo, lógica, conversiones raras de bases (👀 último ejercicio).
	Pros: legible, potente, libs infinitas.
	Contras: no siempre permitido en ejercicios low-level.

👉 Muchos scripts difíciles en shell se vuelven 10x más simples en Python.

⸻

🟣 Perl

El abuelo oscuro pero OP.
•	Nació para text processing.
•	Pros: regex ultra potente, una-línea dios.
•	Contras: legibilidad… questionable.

👉 Muchas joyas tipo:
	perl -ne 'print if $. % 2'

⸻

🟡 Awk

Mini-lenguaje escondido en el shell.
•	Pros: rápido, perfecto para columnas y líneas.
•	Contras: no es generalista.

👉 Ideal para /etc/passwd, contadores, filtros.

⸻

🔵 Ruby

Elegante y expresivo.
•	Pros: scripts limpios y humanos.
•	Contras: no siempre instalado por defecto.

⸻

🟢 Node.js (JavaScript)

Sí, también vale.
•	Pros: JS everywhere, buen manejo de strings.
•	Contras: overkill para tareas simples del sistema.

⸻

⚙️ C

Modo hard.
•	Pros: control total.
•	Contras: compilar para algo que sed hace en 1 línea 🤡

⸻

🧠 Regla mental rápida
•	Sistema + pipes → Shell
•	Texto complejo / lógica rara → Python / Perl
•	Columnas y filtros → Awk
•	Conversión de bases custom → Python (sin sufrir)

⸻

💡 Real talk:
En la vida real, la gente mezcla. Shell para orquestar, Python para pensar.
Si quieres, dime un ejercicio concreto y te digo:
•	qué lenguaje usaría yo
•	por qué
•	y cómo se vería la versión más clean 🔥

