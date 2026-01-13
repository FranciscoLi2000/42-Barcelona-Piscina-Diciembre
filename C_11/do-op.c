/* do-op.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* A tolerant atoi: skip leading spaces, accept sequence of + and - before digits,
 * then parse digits until non-digit (behaves like many 42 piscine solutions). */

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	*op;

	if (argc != 4)
		return 0;
	a = atoi(argv[1]);
	op = argv[2];
	b = atoi(argv[3]);
	if (strcmp(op, "+") == 0)
		printf("%d\n", a + b);
	else if (strcmp(op, "-") == 0)
		printf("%d\n", a - b);
	else if (strcmp(op, "*") == 0)
		printf("%d\n", a * b);
	else if (strcmp(op, "/") == 0)
	{
		if (b == 0)
			printf("Stop : division by zero\n");
		else
			printf("%d\n", a / b);
	}
	else if (strcmp(op, "%") == 0)
	{
		if (b == 0)
			printf("Stop : modulo by zero\n");
		else
			printf("%d\n", a % b);
	}
	else
		printf("0\n");
	return 0;
}
