#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // pour toupper, tolower
#include "../libft.h"  // pour ft_toupper, ft_tolower

typedef struct s_toupper_tolower_test
{
    char c;
    const char *comment;
} t_toupper_tolower_test;

void test_uplow(void)
{
    t_toupper_tolower_test tests[] = {
        {'a', "lowercase to uppercase"},
        {'z', "lowercase to uppercase"},
        {'A', "already uppercase"},
        {'Z', "already uppercase"},
        {'0', "digit (no change)"},
        {' ', "space (no change)"},
        {'!', "special char (no change)"},
    };

    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

    printf("\nft_toupper / ft_tolower tests:	");

    while (i < num_tests)
    {
        char ft_toupper_result = ft_toupper(tests[i].c);
        char ft_tolower_result = ft_tolower(tests[i].c);
        char std_toupper_result = toupper(tests[i].c);
        char std_tolower_result = tolower(tests[i].c);

        if (ft_toupper_result == std_toupper_result && ft_tolower_result == std_tolower_result)
        {
            ok_count++;
        }
        else
        {
            fail_count++;
            printf("Test %zu (%s) : KO\n", i + 1, tests[i].comment);
            printf("ft_toupper: Expected '%c', Got '%c'\n", std_toupper_result, ft_toupper_result);
            printf("ft_tolower: Expected '%c', Got '%c'\n", std_tolower_result, ft_tolower_result);
        }
        i++;
    }

    if (fail_count == 0)
        printf("\t\tOK");
    else
        printf("\n%zu tests OK, %zu tests KO\n", ok_count, fail_count);
}