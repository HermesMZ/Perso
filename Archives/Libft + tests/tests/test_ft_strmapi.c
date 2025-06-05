#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

static char	ft_test(unsigned int i, char test)
{
	test -= 32;
	i++;
	return (test);
}

void	test_ft_strmapi(void)
{
    char	test[] = "abcd";
	char	expected[] = "ABCD";
	char	*result;
	

    printf("\nft_strmapi tests :		");
	result = ft_strmapi(test, &ft_test);
	if (strcmp(result, expected) == 0)
		printf("\t\tOK");
    else
		printf("Test failed: expected \"%s\" got \"%s\"\n", expected, result);
	free(result);
}
