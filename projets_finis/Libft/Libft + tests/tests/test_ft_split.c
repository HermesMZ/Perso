#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

static void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

typedef struct s_split_test
{
    const char *s;
    const char c;
    char	*result[10];
    const char *comment;
} 				t_split_test;

void test_ft_split(void)
{
    t_split_test tests[] = 
	{
        {"xxxxxxxxxxchaton", 'x',{"chaton"}, "First characters"},
        {"chatonxxxxxxxxxx", 'x',{"chaton"}, "Last characters"},
        {"\n\n\n\nchaton", '\n',{"chaton"}, "non-print characters"},
        {"", 'x', {NULL}, "Empty src"},
        {"", '\0', {NULL}, "Empty src && no charset"},
        {"chaton", 'x', {"chaton"}, "Charset not found"},
        {"chaton", '\0', {"chaton"}, "no Charset"},
        {"xxxxxxx", 'x', {"chaton"}, "only charset"},
        {"xxxchxxxxatxxxxxonxxxx", 'x', {"ch", "at", "on"}, "multi strings"},
    };
    size_t i = 0;
    size_t j = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;
	char	**result;

    printf("\nft_split tests :		");

    while (i < num_tests)
    {
        result = ft_split(tests[i].s, tests[i].c);
		j = 0;
		while (result[j] && tests[i].result[j])
		{	
			if (strcmp(result[j], tests[i].result[j])== 0)
				ok_count++;
			else
			{
				fail_count++;
				printf("Test failed: %s\n", tests[i].comment);
			}
			j++;
		}
		free_splitted(result);
        i++;
    }
    if (fail_count == 0)
        printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}