#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

typedef struct s_memmove_test
{
    void *dest;
    const void *src;
    size_t n;
    const char *comment;
} t_memmove_test;

void test_ft_memmove(void)
{
    t_memmove_test tests[] = {
        {(void *)"abcdef", (const void *)"abcdef", 3, "Non-overlapping: src == dest"},
        {(void *)"abcdef", (const void *)"123456", 3, "Non-overlapping: different src & dest"},
        {(void *)"abcdef", (const void *)"abcdef", 3, "Overlapping: src starts before dest (copy backward)"},
        {(void *)"abcdef", (const void *)"abcdef", 3, "Overlapping: dest starts before src (copy forward)"},
        {(void *)"abcdef", (const void *)"123456", 6, "Equal size memcpy"},
        {(void *)"abcdef", (const void *)"123456", 10, "n > size of memory"},
        {(void *)"abcdef", (const void *)"abcdef", 0, "n = 0 (no move)"},
        {(void *)"abcdef", (const void *)"abcdef", 1, "Single byte move"},
    };

    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

	printf("\nft_memmove tests :		");

    while (i < num_tests)
    {
        void *ft_dest = malloc(50);
        void *std_dest = malloc(50);
        
        if (!ft_dest || !std_dest)
        {
            printf("Memory allocation failed\n");
            return;
        }

        memcpy(ft_dest, tests[i].dest, 50);
        memcpy(std_dest, tests[i].dest, 50);

        ft_memmove(ft_dest, tests[i].src, tests[i].n);
        memmove(std_dest, tests[i].src, tests[i].n);

        if (memcmp(ft_dest, std_dest, tests[i].n) == 0)
            ok_count++;
        else
        {
            fail_count++;
            printf("Test failed: %s\n", tests[i].comment);
        }

        free(ft_dest);
        free(std_dest);

        i++;
    }

    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}
