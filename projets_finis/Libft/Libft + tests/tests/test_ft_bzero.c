#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

typedef struct s_bzero_test
{
    const char        str[50];
    size_t      n;
    size_t      total_size;
    const char  *comment;
}				t_bzero_test;

void	test_ft_bzero(void)
{
	size_t	i = 0;
	size_t	ok_count = 0;
	size_t	fail_count = 0;
	char	ft_str[50];
	char	std_str[50];

	const t_bzero_test bzero_tests[] = {
		{ "1234", 2, sizeof("1234"), "cas standard" },
		{ "1234", 0, sizeof("1234"), "n = 0" },
		{ "1234", sizeof("1234"), sizeof("1234"), "on efface tout" },
		{ "1234", 10, 50, "n > taille des données" },
		{ "0\t\n1", 4, sizeof("0\t\n1"), "non printable" },
		{ "", 1, 1, "chaine vide" }
	};
	size_t num_tests = sizeof(bzero_tests) / sizeof(bzero_tests[0]);

	printf("\nft_bzero standard tests :	");
	while (i < num_tests)
	{
		memset(ft_str, 'A', sizeof(ft_str));
		memset(std_str, 'A', sizeof(ft_str));
		ft_strlcpy(ft_str, bzero_tests[i].str, sizeof(ft_str));
		ft_strlcpy(std_str, bzero_tests[i].str, sizeof(std_str));
		ft_bzero(ft_str, bzero_tests[i].n);
		bzero(std_str, bzero_tests[i].n);
		if (memcmp(ft_str, std_str, bzero_tests[i].n) == 0)
			ok_count++;
		else
		{
			fail_count++;
			printf("test %zu (%s) : KO\n", i + 1, bzero_tests[i].comment);
		}
		i++;
	}
	if (fail_count == 0)
		printf("\t\tOK\n");
	else
		printf("\n%ld tests OK. There are still %ld tests KO\n", ok_count, fail_count);
// ===================================================================
	printf("	Test for NULL pointers and n = 0 :	");
	char *null_ft_str = NULL;
    char *null_std_str = NULL;
	ft_bzero(null_ft_str, 0);
	bzero(null_std_str, (0));
	printf("OK\n");
	ok_count++;
// ===================================================================

	printf("	Test on malloc string : 		");
	size_t size = 8;
	char *malloc_ft_str = malloc(size);
	char *malloc_std_str = malloc(size);

	if (!malloc_ft_str || !malloc_std_str)
	{
		printf("malloc failed");
		return ;
	}
	memset(malloc_ft_str, 'x', size);
	memset(malloc_std_str, 'x', size);
	ft_bzero(malloc_ft_str, size);
	bzero(malloc_std_str, size);

	if (memcmp(malloc_ft_str, malloc_std_str, size) == 0)
	{
		ok_count++;
		printf("OK\n");
	}
	else
	{
		printf("ft_bzero : %s != %s : bzero\n", malloc_ft_str, malloc_std_str);
		fail_count++;
	}

	free(malloc_ft_str);
	free(malloc_std_str);

	if (fail_count != 0)
		printf("\n%ld tests OK. There are still %ld tests KO\n", ok_count, fail_count);
}
