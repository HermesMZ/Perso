#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void	test_ft_atoi(void)
{
	int	i = 0;
	int	ok_count = 0;
	int	fail_count = 0;
	int	num_tests = 14;
	const char *test[] = {
        "",
        "0",
		"123",
        "   123",
        "+123",
        "-123",
        "+-123",
        " + 123",
        " - 123",
        "2147483647",
        "-2147483648",
        "abc",
        "123abc456",
        " \t\n\r\v\f 123"
	};

	printf("\nft_atoi tests :			");
	while (i < num_tests)
	{
		int result_ft = ft_atoi(test[i]);
		int	result_std = atoi(test[i]);
		if ( result_ft == result_std)
		{
			ok_count++;
		}
		else
		{
			fail_count++;
			printf("test ft_atoi pour %s : KO\n", test[i]);
			printf("ft_atoi : %d différent de atoi : %d\n", result_ft, result_std);
		}
		i++;
	}
	if (fail_count == 0)
		printf("\t\tOK");
	else
		printf("\n%d tests OK. There are still %d tests KO\n", ok_count, fail_count);
}
