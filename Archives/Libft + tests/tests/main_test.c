#include <stdio.h>

void	test_characters(void);
void	test_ft_atoi(void);
void	test_ft_bzero(void);
void	test_ft_calloc(void);
void	test_ft_itoa(void);
void	test_ft_memchr(void);
void	test_ft_memcpy(void);
void	test_ft_memcmp(void);
void	test_ft_memset(void);
void	test_ft_memmove(void);
void	test_ft_putchar_fd(void);
void	test_ft_putendl_fd(void);
void	test_ft_putnbr_fd(void);
void	test_ft_putstr_fd(void);
void	test_ft_split(void);
void	test_ft_strchr(void);
void	test_ft_strdup(void);
void	test_ft_striteri(void);
void	test_ft_strjoin(void);
void	test_ft_strlcat(void);
void	test_ft_strlcpy(void);
void	test_ft_strmapi(void);
void	test_ft_strlen(void);
void	test_ft_strncmp(void);
void	test_ft_strnstr(void);
void	test_ft_strrchr(void);
void	test_ft_strtrim(void);
void	test_ft_substr(void);
void	test_ft_lst(void);
void 	test_uplow(void);


int main(void)
{
    printf("===== Lancement des tests =====\n");
    
    test_characters();
	test_uplow();
    test_ft_atoi();
    test_ft_itoa();
    test_ft_bzero();
    test_ft_calloc();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_memset();
	test_ft_putchar_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_ft_putstr_fd();
	test_ft_split();
	test_ft_strchr();
	test_ft_strdup();
	test_ft_strjoin();
	test_ft_strlcat();
	test_ft_strlcpy();
	test_ft_strlen();
	test_ft_strnstr();
	test_ft_striteri();
	test_ft_strmapi();
    test_ft_strncmp();
	test_ft_strrchr();
	test_ft_strtrim();
	test_ft_substr();
	test_ft_lst();


    printf("\n===== Tous les tests terminés =====\n");
    return 0;
}
