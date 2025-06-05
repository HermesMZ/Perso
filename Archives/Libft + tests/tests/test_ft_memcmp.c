#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_memcmp_test
{
    const void *s1;
    const void *s2;
    size_t n;
    const char *comment;
} 				t_memcmp_test;

void	test_ft_memcmp(void)
{
	t_memcmp_test tests[] =
	{
        {"abcd", "abyz", 4, "same first letters, second string is longer"},
		{"abcd", "abcd", 4, "identical strings"},
        {"abcd", "abce", 4,  "first differs in last character"},
        {"abcd", "ab\0\0\0", 4, "second string is shorter"},
        {"abcd", "abcd", 0, "n == 0"},
        {"abcd", "ab\0c", 4, "null middle"},
        {"\0abc", "\0abc", 4, "null beginning"},
    };
    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

	printf("\nft_memcmp tests :		");
    while (i < num_tests)
    {
        int std = memcmp(tests[i].s1, tests[i].s2, tests[i].n);
        int ft = ft_memcmp(tests[i].s1, tests[i].s2, tests[i].n);

        if (ft == std)
            ok_count++;
        else
        {
            fail_count++;
            printf("\nTest failed: %s ", tests[i].comment);
            printf("Expected: %d, Got: %d\n", std, ft);
        }
        i++;
    }

    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}