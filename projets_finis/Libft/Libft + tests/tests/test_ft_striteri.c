#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

static void	ft_test(unsigned int i, char *test)
{
	if (*test >= 'a' && *test <= 'z')
		*test -= 32;
	else if (*test >= 'A' && *test <= 'Z')
		*test += 32;
	i++;
}

void	test_ft_striteri(void)
{
    char	test[] = "abcd";
	char	result[] = "ABCD";

    printf("\nft_striteri tests :		");
	ft_striteri(test, &ft_test);
	if (strcmp(test, result) == 0)
		printf("\t\tOK");
    else
		printf("Test failed: expected \"%s\" got \"%s\"\n", result, test);
}
