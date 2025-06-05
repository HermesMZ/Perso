#include "libft.h"
#include <stdio.h>

void	test_ft_lstadd_front(void)
{
	int	content0 = 1;
	int	content1 = 1;
	t_list	*test0;
	t_list	*test1;
	t_list *head = NULL;


	test0 = ft_lstnew(&content0);
	if (!test0)
		return ;
	test1 = ft_lstnew(&content1);
	if (!test1)
	{
		free(test0);
		return ;
	}

	head = test1;
	
	printf("\nft_lstadd_front tests :			");
	ft_lstadd_front(&head, test0);
	if (head == test0 && test0->next == test1)
		printf("\t\tOK");
	else
		printf("test KO");

	free(test0);
	free(test1);
}