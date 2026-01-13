/* 2. Push front (insertar al inicio) */

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return;
	new->next = *begin_list;
	*begin_list = new;
}

/* Doble puntero = quieres modificar la cabeza */
