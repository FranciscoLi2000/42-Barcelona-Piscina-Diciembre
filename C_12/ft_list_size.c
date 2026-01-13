/* 3. Tamaño de la lista */

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return count;
}

/* O(n), normal, no magia */
