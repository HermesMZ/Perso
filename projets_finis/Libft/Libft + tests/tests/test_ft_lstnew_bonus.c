#include "libft.h"
#include <stdio.h>

void	test_ft_lstnew(void)
{
	int	content1 = 1;
	t_list	*test1;

	printf("\nft_lstnew tests :			");

	test1 = ft_lstnew(&content1);
	if (!test1)
		return ;
	if (test1->content == &content1)
		printf("\t\t\tOK");
	else
		printf("test KO");
	free(test1);
}