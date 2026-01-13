/* Remove if (difícil pero clave) */

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*curr = *begin_list;
	t_list	*prev = NULL;

	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*begin_list = curr->next;
			free_fct(curr->data);
			free(curr);
			curr = (prev) ? prev->next : *begin_list;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
