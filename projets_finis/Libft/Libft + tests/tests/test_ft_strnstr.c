#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_strnstr_test
{
    const char *big;
    const char *little;
    size_t n;
    const char *comment;
} 				t_strnstr_test;

void test_ft_strnstr(void)
{
    t_strnstr_test tests[] = 
	{
        {"abcdef", "ab", 2, "First character"},
        {"abcdef", "ef", 2, "Last character"},
        {"abcdef", "fg", 2, "Character not found"},
        {"abcdef", "cd", 2, "Middle character"},
        {"abcdef", "ab", 5, "n > size"},
        {"abcdef", "a", 0, "n = 0 (no bytes to search)"},
        {"abcdef", "", 3, "empty search"},
        {"abcdef", "", 0, "empty search && n = 0"},
    };
    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

    printf("\nft_strnstr tests :		");

    while (i < num_tests)
    {
        void *ft_result = ft_strnstr(tests[i].big, tests[i].little, tests[i].n);
        void *std_result = strnstr(tests[i].big, tests[i].little, tests[i].n);

        if (ft_result == std_result)
            ok_count++;
        else
        {
            fail_count++;
            printf("Test failed: %s\n", tests[i].comment);
            if (ft_result)
                printf("ft_strnstr found at: %p\n", ft_result);
            else
                printf("ft_strnstr not found\n");

            if (std_result)
                printf("strnstr found at: %p\n", std_result);
            else
                printf("strnstr not found\n");
        }
        i++;
    }

    if (fail_count == 0)
        printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}