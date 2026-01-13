/* Reverse (cambia punteros) */

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev = NULL;
	t_list	*curr = *begin_list;
	t_list	*next;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}

/* Esto sale mucho en entrevistas */
