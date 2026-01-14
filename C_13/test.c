#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

/* comparator para ints */
int	cmp_int(void *a, void *b)
{
	int ia = *(int *)a;
	int ib = *(int *)b;

	if (ia < ib)
		return -1;
	if (ia > ib)
		return 1;
	return 0;
}

/* funciones de impresión */
void	print_item(void *item)
{
	printf("%d ", *(int *)item);
}

void	print_by_level(void *item, int lvl, int is_first)
{
	if (is_first)
		printf("[level %d] ", lvl);
	printf("%d ", *(int *)item);
	if (is_first == 0) /* solo para mantener espacio o formato; opcional */
		(void)0;
}

int	main(void)
{
	int *nums[7];
	int vals[7] = {5, 3, 7, 2, 4, 6, 8};
	t_btree *root = NULL;
	int i;

	for (i = 0; i < 7; ++i)
	{
		nums[i] = malloc(sizeof(int));
		*nums[i] = vals[i];
		btree_insert_data(&root, nums[i], cmp_int);
	}
	printf("Infix (in-order): ");
	btree_apply_infix(root, print_item);
	printf("\n");
	printf("Prefix: ");
	btree_apply_prefix(root, print_item);
	printf("\n");
	printf("Suffix: ");
	btree_apply_suffix(root, print_item);
	printf("\n");
	printf("By level:\n");
	btree_apply_by_level(root, print_by_level);
	printf("\n");
	/* search */
	int key = 4;
	int *found = btree_search_item(root, &key, cmp_int);
	if (found)
		printf("Found: %d\n", *found);
	else
		printf("Not found\n");
	/* liberado rápido (sin borrar nodos para que el ejemplo sea corto) */
	for (i = 0; i < 7; ++i)
		free(nums[i]);
	return 0;
}

/* Notas rápidas (por qué funciona así)
 * •	cmpf(a, b) se usa como strcmp: negativo si a < b, 0 si iguales, positivo si a > b. En btree_insert_data uso cmpf(item, node->item) < 0 para decidir izquierda/derecha (iguales van a la derecha, según tu enunciado).
 * •	btree_search_item recorre en infix y devuelve el primer match (cmpf(…) == 0).
 * •	btree_apply_by_level implementado sin cola: para cada nivel L recorro todo el árbol y aplico solo a nodos con current_level==L. Es O(n * h) en peor caso (h = altura). Para árboles grandes y necesidad de máxima eficiencia, se podría usar una cola BFS iterativa (O(n)) — si quieres te la paso también.
 */

