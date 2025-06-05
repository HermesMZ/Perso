#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

typedef struct s_test_ft_substr
{
	const char	s[10];
	unsigned int	start;
	size_t	len;
	const char	*expected;
}				t_test_ft_substr;


void	test_ft_substr(void)
{
	t_test_ft_substr	tests[] = 
	{
		{"123456", 0, 6, "123456"},
		{"123456", 0, 3, "123"},
		{"123456", 3, 3, "456"},
		{"123456", 3, 0, ""},
		{"123456", 3, 10, "456"},
		{"", 0, 3, ""},
	};
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	size_t	ok_count = 0;
    size_t	fail_count = 0;
	char	*ft;

	printf("\nft_substr tests :\t\t");
	while (i < num_tests)
	{
		ft = ft_substr(tests[i].s, tests[i].start, tests[i].len);
		if ((!ft && !tests[i].expected) || (strcmp(ft, tests[i].expected) == 0))
			ok_count++;
		else
		{
			fail_count++;
			printf("\n%zu KO (expected \"%s\", got \"%s\")\n", i + 1, tests[i].expected, ft);
		}
		free(ft);
		i++;
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}