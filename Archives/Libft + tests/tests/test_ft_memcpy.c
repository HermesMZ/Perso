#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

typedef struct s_memcpy_test
{
    void *dest;
    const void *src;
    size_t n;
    const char *expected_result;
    const char *comment;
} t_memcpy_test;

void	test_ft_memcpy(void)
{
	{
		t_memcpy_test tests[] = {
			{ (void *)"abcdef", (const void *)"123456", 3, "123", "Copy part of string (n < size)" },
			{ (void *)"abcdef", (const void *)"123456", 6, "123456", "Copy full string (n == size)" },
			{ (void *)"abcdef", (const void *)"123456", 8, "123456", "Copy more than available (n > size)" },
			{ (void *)"abcdef", (const void *)"", 0, "", "Copy empty string (n = 0)" },
		};
	
		size_t i = 0;
		size_t num_tests = sizeof(tests) / sizeof(tests[0]);
		size_t ok_count = 0;
		size_t fail_count = 0;
	
		printf("\nft_memcpy tests :		");
	
		while (i < num_tests)
		{
			char ft_dest[50];
			char std_dest[50];
	
			ft_memcpy(ft_dest, tests[i].src, tests[i].n);
			memcpy(std_dest, tests[i].src, tests[i].n);
	
			if (memcmp(ft_dest, std_dest, tests[i].n) == 0)
			{
				ok_count++;
			}
			else
			{
				fail_count++;
				printf("Test failed: %s\n", tests[i].comment);
				printf("Expected: %s, Got: %s\n", std_dest, ft_dest);
			}
			i++;
		}
	
		if (fail_count == 0)
			printf("\t\tOK");
		else
			printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
	}

}