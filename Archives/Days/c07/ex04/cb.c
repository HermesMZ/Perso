#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str && str[i] != '\0')
        i++;
    return (i);
}

int base_check(char *base)
{
    int base_size;
    int i;
    int j;

    if (!base || base[0] == '\0')
        return (0);

    base_size = ft_strlen(base);
    if (base_size < 2)
        return (0);
    for (i = 0; i < base_size; i++)
    {
        for (j = i + 1; j < base_size; j++)
        {
            if (base[i] == base[j])
            {
                return (0);
            }
        }
        if (base[i] == '-' || base[i] == '+' || (base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
            return (0);
    }
    return (base_size);
}

int ft_digits_count(int atoi, int to_size)
{
    int i;
    long n;

    n = atoi;
    if (n == 0)
        return (1);
    i = 0;
    if (n < 0)
    {
        i++;
        n = -n;
    }
    while (n != 0)
    {
        n /= to_size;
        i++;
    }
    return (i);
}

int find_number(char nb, char *base, int base_size)
{
    int i;

    i = 0;
    while (i < base_size)
    {
        if (nb == base[i])
            return (i);
        i++;
    }
    return (-1);
}

int ft_atoi_base(char *str, char *base)
{
    int sign;
    long number;
    int base_size;
    int digit;

    base_size = base_check(base);
    if (!base_size)
        return (0);
    sign = 1;
    while ((*str >= '\t' && *str <= '\r') || *str == ' ')
        str++;
    while (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    number = 0;
    while (*str != '\0')
    {
        digit = find_number(*str, base, base_size);
        if (digit == -1)
            break;
        number = number * base_size + digit;
        str++;
    }
    return (number * sign);
}

void ft_putnbr_base(char *result, long atoi, char *base, int *index)
{
    int base_size;

    base_size = ft_strlen(base);
    if (atoi < 0)
    {
        result[(*index)++] = '-';
        atoi *= -1;
    }
    if (atoi >= base_size)
    {
        ft_putnbr_base(result, atoi / base_size, base, index);
        ft_putnbr_base(result, atoi % base_size, base, index);
    }
    else
        result[(*index)++] = base[atoi];
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    char *result;
    long atoi;
    int result_size;
    int from_size, to_size;
    int index;

    from_size = base_check(base_from);
    to_size = base_check(base_to);
    if (!from_size || !to_size)
        return (NULL);
    atoi = ft_atoi_base(nbr, base_from);
    result_size = ft_digits_count(atoi, to_size);
    result = malloc(sizeof(char) * (result_size + 1));
    if (!result)
        return (NULL);
    index = 0;
    if (atoi == 0)
        result[index++] = base_to[0];
    else
        ft_putnbr_base(result, atoi, base_to, &index);
    result[index] = '\0';
    return (result);
}

int main(void)
{
	char	base_from[] = "01";
	char	base_to[] = "0123456";
	char	nbr[] = "--01234";
    char *result = ft_convert_base(nbr, base_from, base_to);
    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    else
    {
        printf("Error\n");
    }
    return (0);
}