#include "btree.h"

/* level count (height) */
static int	max_int(int a, int b)
{
	return (a > b ? a : b);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + max_int(btree_level_count(root->left), btree_level_count(root->right)));
}

/* helper for apply_by_level: traverse with current_level, target_level and flag pointer */
static void	apply_level_helper(t_btree *root, int target_level, int current_level, void (*applyf)(void *, int, int), int *is_first_ptr)
{
	if (!root)
		return ;
	if (current_level == target_level)
	{
		applyf(root->item, target_level, *is_first_ptr);
		*is_first_ptr = 0;
		return ;
	}
	apply_level_helper(root->left, target_level, current_level + 1, applyf, is_first_ptr);
	apply_level_helper(root->right, target_level, current_level + 1, applyf, is_first_ptr);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		height;
	int		lvl;
	int		is_first;

	if (!root || !applyf)
		return ;
	height = btree_level_count(root);
	for (lvl = 0; lvl < height; ++lvl)
	{
		is_first = 1;
		apply_level_helper(root, lvl, 0, applyf, &is_first);
	}
}
