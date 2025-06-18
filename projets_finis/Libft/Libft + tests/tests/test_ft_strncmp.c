#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_strncmp_test
{
    const void *s1;
    const void *s2;
    size_t n;
    const char *comment;
} 				t_strncmp_test;

void	test_ft_strncmp(void)
{
	t_strncmp_test tests[] =
	{
        {"abcd\200", "abcd", 6, "non print"},
        {"abcd", "abcd", 4, "identical strings"},
        {"abcd", "abce", 4, "first differs in last character"},
        {"abcd", "ab", 4, "second string is shorter"},
        {"abcd", "abxyz", 4, "same first letters, second string is longer"},
        {"abcd", "abcd", 0, "n == 0"},
        {"", "", 5, "empty strings"},
        {"a", "", 1, "first non-empty, second empty"},
        {"", "b", 1, "first empty, second non-empty"},
        {"abcdefg", "abcxyz", 3, "differ at the 4th char, n=3"},
        {"abcdefg", "abcxyz", 5, "differ at the 4th char, n=5"},
        {"test\0string", "test\0another", 10, "null byte in the middle"},
        {"\0abc", "\0def", 4, "null byte at the beginning"},
    };
    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

	printf("\nft_strncmp tests :		");
    while (i < num_tests)
    {
        int ft_result = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);
        int std_result = strncmp(tests[i].s1, tests[i].s2, tests[i].n);

		if ((ft_result > 0 && std_result > 0) || (ft_result < 0 && std_result < 0) || (ft_result == std_result))
            ok_count++;
        else
        {
            fail_count++;
            printf("\nTest failed: %s ", tests[i].comment);
            printf("Expected: %d, Got: %d\n", std_result, ft_result);
        }
        i++;
    }

    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}