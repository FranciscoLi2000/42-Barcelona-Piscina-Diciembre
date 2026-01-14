#include "btree.h"

/* insert: lower to left, higher or equal to right */
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
