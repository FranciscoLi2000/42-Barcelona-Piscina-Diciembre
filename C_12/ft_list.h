#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

/* 0. Mental model (重要)

Una linked list es literalmente:

[data] -> [data] -> [data] -> NULL

•	No índices ❌
•	Todo es punteros
•	El poder está en next

Tu struct ya está perfecto:
*/
typedef struct s_list
{
	struct s_list	*next;
	void		*data;
}	t_list;

/* void *data = universal USB, mete lo que quieras 🔌 */

#endif
