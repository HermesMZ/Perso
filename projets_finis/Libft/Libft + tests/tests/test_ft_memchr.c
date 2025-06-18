#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_memchr_test
{
    void *ptr;
    int c;
    size_t n;
    const char *comment;
} 				t_memchr_test;

void test_ft_memchr(void)
{
    t_memchr_test tests[] = 
	{
        {(void *)"abcdef", 'a', 6, "First character"},
        {(void *)"abcdef", 'f', 6, "Last character"},
        {(void *)"abcdef", 'z', 6, "Character not found"},
        {(void *)"abcdef", 'd', 6, "Middle character"},
        {(void *)"abcdef", 'a', 0, "n = 0 (no bytes to search)"},
        {(void *)"abcdef", 'c', 3, "Character in first part"},
        {(void *)"abcdef", 'c', 2, "Character in second part"},
        {(void *)"abcdef", 'a', 1, "Single byte search (found)"},
        {(void *)"abcdef", 'z', 1, "Single byte search (not found)"},
    };

    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

    printf("\nft_memchr tests :		");

    while (i < num_tests)
    {
        void *ft_result = ft_memchr(tests[i].ptr, tests[i].c, tests[i].n);
        void *std_result = memchr(tests[i].ptr, tests[i].c, tests[i].n);

        if (ft_result == std_result)
            ok_count++;
        else
        {
            fail_count++;
            printf("Test failed: %s\n", tests[i].comment);
            if (ft_result)
                printf("ft_memchr found at: %p\n", ft_result);
            else
                printf("ft_memchr not found\n");

            if (std_result)
                printf("memchr found at: %p\n", std_result);
            else
                printf("memchr not found\n");
        }
        i++;
    }

    if (fail_count == 0)
        printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}