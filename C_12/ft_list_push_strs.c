/* Push strs (muy 42-style)
 * El primer string termina al final
 */

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_back(&list, strs[i]);
		i++;
	}
	return list;
}
