/* Push back (insertar al final) */

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return;
	if (!*begin_list)
	{
		*begin_list = new;
		return;
	}
	ft_list_last(*begin_list)->next = new;
}
