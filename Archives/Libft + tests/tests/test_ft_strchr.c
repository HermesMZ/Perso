#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_strchr_test
{
    void *ptr;
    int c;
    const char *comment;
} 				t_strchr_test;

void test_ft_strchr(void)
{
    t_strchr_test tests[] = 
	{
        {(void *)"abcdef", 'a', "First character"},
        {(void *)"abcdef", 'f', "Last character"},
        {(void *)"abcdef", 'z', "Character not found"},
        {(void *)"abcdef", 'd', "Middle character"},
    };

    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

    printf("\nft_strchr tests :		");

    while (i < num_tests)
    {
        void *ft_result = ft_strchr(tests[i].ptr, tests[i].c);
        void *std_result = strchr(tests[i].ptr, tests[i].c);

        if (ft_result == std_result)
            ok_count++;
        else
        {
            fail_count++;
            printf("Test failed: %s\n", tests[i].comment);
            if (ft_result)
                printf("ft_strchr found at: %p\n", ft_result);
            else
                printf("ft_strchr not found\n");

            if (std_result)
                printf("strchr found at: %p\n", std_result);
            else
                printf("strchr not found\n");
        }
        i++;
    }

    if (fail_count == 0)
        printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}