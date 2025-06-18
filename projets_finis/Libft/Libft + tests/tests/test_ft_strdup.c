#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../libft.h"

void	test_ft_strdup(void)
{
	const char	*tests[] = 
	{
		"",
		" ",
		"abcde",
		"\nabcde",
		"\nabcde\n"
	};
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	size_t	ok_count = 0;
    size_t	fail_count = 0;
	char	*ft_result;
	char	*std_result;

	printf("\nft_strdup tests :\t\t");
	while (i < num_tests)
	{
		ft_result = ft_strdup(tests[0]);
		std_result = ft_strdup(tests[0]);

		if (strcmp(ft_result, std_result) == 0)
			ok_count++;
		else
		{
			fail_count++;
			printf("ft_strdup : KO (expected \"%s\", got \"%s\")\n", std_result, ft_result);
		}
		i++;
		free(ft_result);
		free(std_result);
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}