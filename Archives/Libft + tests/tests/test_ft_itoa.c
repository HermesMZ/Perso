#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

void	test_ft_itoa(void)
{
    const int tests[] = {
        0,
        -1,
        1,
        42,
        -42,
        2147483647,
        -2147483648
    };

    size_t i = 0;
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t ok_count = 0;
    size_t fail_count = 0;

	printf("\nft_itoa tests :			");
    while (i < num_tests)
    {
        char *ft_result = ft_itoa(tests[i]);
        char std_result[12];
        sprintf(std_result, "%d", tests[i]);

        if (ft_result == NULL)
        {
            printf("ft_itoa failed for input %d\n", tests[i]);
            fail_count++;
            i++;
            continue;
        }

        if (strcmp(ft_result, std_result) != 0)
        {
            printf("Test failed for input %d\n", tests[i]);
            printf("Expected: %s, Got: %s\n", std_result, ft_result);
            fail_count++;
        }
        else
        {
            ok_count++;
        }

        free(ft_result);
        i++;
    }
	if (fail_count == 0)
		printf("\t\tOK");
	else
		printf("\n%zu tests OK. There are still %zu tests KO\n", ok_count, fail_count);
}
