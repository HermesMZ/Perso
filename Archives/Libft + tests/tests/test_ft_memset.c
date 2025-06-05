#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

typedef struct s_memset_test
{
	char	*s;
    int	c;
    size_t	n;
    const char  *comment;
}				t_memset_test;

void	test_ft_memset(void)
{
	t_memset_test	tests[] = 
	{
		{"12345", 'x', 5, "n = size"},
		{"12345", 0, 5, "set all to \\0"},
		{"12345", 'x', 0, "n = 0"},
		{"12345", 'x', 3, "n < size"},
		{"12345", 'x', 10, "n > size"},
		{"", 'x', 5, "Empty string"},
		{"12345", 200, 5, "cast test"}
	};
	size_t	i = 0;
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	ok_count = 0;
	size_t	fail_count = 0;

	printf("\nft_memset tests :		");
	while (i < num_tests)
	{
		char	ft_ptr[50];
		char	std_ptr[50];
		size_t	len = strlen(tests[i].s);
		
		memcpy(ft_ptr, tests[i].s, len + 1);
		memcpy(std_ptr, tests[i].s, len + 1);

		ft_memset(ft_ptr, tests[i].c, tests[i].n);
		memset(std_ptr, tests[i].c, tests[i].n);

		if (memcmp(ft_ptr, std_ptr, tests[i].n) == 0)
			ok_count++;
		else
		{
			fail_count++;
			printf("test %zu (%s) : KO\n", i + 1, tests[i].comment);
		}
		i++;
	}
	if (fail_count == 0)
		printf("\t\tOK");
	else
		printf("\n%ld tests OK. There are still %ld tests KO\n", ok_count, fail_count);
}