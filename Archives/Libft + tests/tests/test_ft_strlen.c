#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../libft.h"

void	test_ft_strlen(void)
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
	size_t	ft_result;
	size_t	std_result;

	printf("\nft_strlen tests :\t\t");
	while (i < num_tests)
	{
		ft_result = ft_strlen(tests[i]);
		std_result = strlen(tests[i]);
		if (ft_result == std_result)
			ok_count++;
		else
		{
			fail_count++;
			printf("ft_strlen : KO (expected \"%zu\", got \"%zu\")\n", std_result, ft_result);
		}
		i++;
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}