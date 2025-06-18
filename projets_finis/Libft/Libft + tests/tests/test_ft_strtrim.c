#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_strtrim_test
{
    const char	*s;
    const char	*set;
    const char	*result;
    const char	*comment;
} 				t_strtrim_test;

void	test_ft_strtrim(void)
{
    t_strtrim_test tests[] = 
	{
        {"xxxzzzzzxxxxxxxchaton", "xz","chaton", "First characters"},
        {"chatonzzzzxxxxxxxxxx", "xz","chaton", "Last characters"},
        {"\n\n\n\nchaton", "\n","chaton", "non-print characters"},
        {"chaton", "x", "chaton", "Charset not found"},
        {"chaton", "", "chaton", "no Charset"},
        {"xxxchxatxonxxx", "x", "chxatxon", "multi strings"},
        {"xxxxxxx", "x", "", "only charset"},
    };
    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

    printf("\nft_strtrim tests :		");

    while (i < num_tests)
    {
        char	*result = ft_strtrim(tests[i].s, tests[i].set);
		if (strcmp(result, tests[i].result)== 0)
		{
			ok_count++;
			// printf("expected \"%s\", got \"%s\"\n", tests[i].result, result);
		}
		else
		{
			fail_count++;
			printf("Test failed: %s\n", tests[i].comment);
			printf("expected \"%s\", got \"%s\"\n", tests[i].result, result);
		}
		free(result);
        i++;
    }
    if (fail_count == 0)
        printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}