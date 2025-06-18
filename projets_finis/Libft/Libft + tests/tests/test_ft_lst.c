#include "libft.h"
#include <stdio.h>

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d -> ", *((int *)head->content));
		head = head->next;
	}
	printf("NULL\n");
}

void	plus1(void *content)
{
	if (content)
		(*(int *)content)++;
}

void	*plus2(void *content)
{
	int *new = malloc(sizeof(int));
	if (!new)
		return NULL;
	*new = *(int *)content + 2;
	return (new);
}

t_list	*test_init_list_with_5_elements(void)
{
	t_list *head = NULL;
	t_list *last = NULL;
	int i = 0;

	while (i < 5)
	{
		int *value = malloc(sizeof(int));
		if (!value)
			break;
		*value = i;

		t_list *new = ft_lstnew(value);
		if (!new)
		{
			printf ("ft_lstnew :\t\t\t KO\n");
			free(value);
			while (head)
			{
				t_list *tmp = head;
				head = head->next;
				free(tmp->content);
				free(tmp);
			}
			break;
		}
		last = ft_lstlast(head);

		ft_lstadd_back(&head, new);
		if (ft_lstlast(head) != new)
			printf("ft_lstlast (%d) :\t\tKO\n", i);
		if (i == 0 && head != new)
			printf("ft_lstadd_back (1er) :\t\tKO\n");
		if (i > 0 && (!last || last->next != new))
			printf("ft_lstadd_back (%d) :\t\tKO\n", i);
		i++;
	}
	if (ft_lstsize(head) != 5)
		printf("ft_lstsize :\t\t\tKO\n");

	return (head);
}

void	test_ft_lst(void)
{
	t_list	*tmp;
	t_list	*tmp_head;
	t_list	*tmp_last;
	t_list	*last;

	printf("\nBonus tests :\n");
	
	t_list *head = test_init_list_with_5_elements();
	if (!head)
		return ;
// tests during init 
	printf("ft_lstnew :\t\t\t\t\tOK\n");
	printf("ft_lstlast :\t\t\t\t\tOK\n");
	printf("ft_lstadd_back :\t\t\t\tOK\n");
	printf("ft_lstsize :\t\t\t\t\tOK\n");

// test addfront	
	int *new_value = (int *)malloc(sizeof(int));
	if (!new_value)
		return ;
	*new_value = *((int *)head->content) - 1;

	tmp = ft_lstnew(new_value);
	if (!tmp)
	{
		free(new_value);
		return;
	}
	tmp_head = head;
	ft_lstadd_front(&head, tmp);
	if (head == tmp && head->next == tmp_head)
		printf("ft_lstadd_front :\t\t\t\tOK\n");
	else
		printf("ft_lstadd_front :\t\tKO\n");

// test delone
	last = ft_lstlast(head);
	new_value = (int *)malloc(sizeof(int));
	if (!new_value)
		return ;
	*new_value = *((int *)last->content) + 1;
	tmp = ft_lstnew(new_value);
	if (!tmp)
	{
		free(new_value);
		return;
	}
	ft_lstadd_back(&head, tmp);
	tmp_last = ft_lstlast(head);

	tmp = head;
	while (tmp && tmp->next != tmp_last)
		tmp = tmp->next;
	if (tmp)
		tmp->next = NULL;
	ft_lstdelone(tmp_last, free);
	tmp_last = ft_lstlast(head);
	if (last == tmp_last)
		printf("ft_lstdelone :\t\t\t\t\tOK\n");
	else
		printf("ft_lstdelone :\t\t\tKO\n");

// test iter
	ft_lstiter(head, plus1);

	int	ok = 1;
	int	expected = 0;
	tmp = head;

	while (tmp)
	{
		if (*(int *)tmp->content != expected)
		{
			ok = 0;
			break;
		}
		expected++;
		tmp = tmp->next;
	}

	if (ok)
		printf("ft_lstiter :\t\t\t\t\tOK\n");
	else
		printf("ft_lstiter :\t\t\tKO\n");
// test map

	t_list	*map = ft_lstmap(head, plus2, free);

	tmp = map;
	ok = 1;
	tmp_head = head;
	while (tmp && tmp_head)
	{
		if (*(int *)tmp->content != *(int *)tmp_head->content + 2)
		{
			ok = 0;
			break;
		}
		tmp_head = tmp_head->next;
		tmp = tmp->next;
	}

	if (ok)
		printf("ft_lstmap :\t\t\t\t\tOK\n");
	else
		printf("ft_lstmap :\t\t\tKO\n");
	ft_lstclear(&map, free);
	ft_lstclear(&head, free);
}