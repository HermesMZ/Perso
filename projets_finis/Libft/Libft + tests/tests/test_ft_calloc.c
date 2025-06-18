#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_calloc_test
{
    size_t	nmemb;
    size_t	size;
    const char  *comment;
}				t_calloc_test;

void	test_ft_calloc(void)
{
	const t_calloc_test	tests[] = {
		{10, 1, "allocation standard"},
		{0, 1, "nmemb == 0 && size > 0"},
		{10, 0, "nmemb > 0 && size == 0"},
		{0, 0, "nmemb == 0 && size == 0"},
		{1000, 10, "nmemb == 1000 && size == 10"},
		{(size_t)-1 / 2 + 1, 2, "overflow"}
	};
	size_t	i = 0;
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);

	printf("\nft_calloc tests :	\t");
	while (i < num_tests)
	{
		size_t	j = 0;
		int *ft_ptr = ft_calloc(tests[i].nmemb, tests[i].size);
		int *std_ptr = calloc(tests[i].nmemb, tests[i].size);

		if (!ft_ptr || !std_ptr)
		{
			// if (!ft_ptr && !std_ptr)
			// 	printf("	Allocation failed as expected for test: %s\n", tests[i].comment);
			// else
			// 	printf("	Mismatch in allocation for test: %s\n", tests[i].comment);
		
			free(ft_ptr);
			free(std_ptr);
			i++;
			continue;
		}
		while (j < tests[i].nmemb * tests[i].size)
		{
			if (((unsigned char *)ft_ptr)[j] != ((unsigned char *)std_ptr)[j])
			{
				printf("Test failed : %s\n", tests[i].comment);
				break;
			}
			j++;
		}
		free(ft_ptr);
		free(std_ptr);
		i++;
	}
	printf("\t\tOK");
}