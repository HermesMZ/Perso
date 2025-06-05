#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../libft.h"

typedef int (*func_ptr)(int);

size_t	tester(func_ptr ft, func_ptr std, char *name)
{
	int car;
	size_t	ok_count = 0;
	size_t	fail_count = 0;

	car = 0;
	while (car <= 255)
	{
		if ((ft(car) != 0) == (std(car) != 0))
			ok_count++;
		else
		{
			fail_count++;
			printf("Test %s for %d (ascii) : KO\n", name, car);
			printf("%s : %d different from : %d\n", name, ft(car), std(car));
		}
		car++;
	}
	return (fail_count);
}
void test_characters(void)
{
	func_ptr ft_functions[] = {ft_isalnum, ft_isalpha, ft_isascii, ft_isdigit, ft_isprint};
	func_ptr libc_functions[] = {isalnum, isalpha, isascii, isdigit, isprint};
	char *function_names[] = {"ft_isalnum", "ft_isalpha", "ft_isascii", "ft_isdigit", "ft_isprint"};

	int	i = 0;
	size_t	total_fail = 0;

	printf("\nCharacter type tests :		");

	while (i < 5)
	{
		total_fail = tester(ft_functions[i], libc_functions[i], function_names[i]);
		i++;
	}
	if (total_fail == 0)
		printf("\t\tOK");
	else
		printf("\nThere are still %zu tests KO\n", total_fail);
}