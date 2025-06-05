#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

// clear && make re && cc tests_bonus.c libftprintf.a -g3 && valgrind --leak-check=full --track-origins=yes -s ./a.out
// clear && find . -name "*.c" | while read file; do clang-tidy "$file" -extra-arg=-std=c99 -quiet -- -I.; done


int main()
{

	setbuf(stdout, NULL);
	// printf(NULL);
	ft_printf(NULL);
//     printf("--- Tests Comparatifs ft_printf vs printf ---\n\n");

// #define YELLOW "\033[33m"
// #define RESET  "\033[0m"

// #define COMPARE(format, arg_display_str, ...) \
//     do { \
//         printf(RESET "Format: \"%s\"\tArgs : \"%s\"\n", format, arg_display_str); \
//         printf(RESET "ft_print: "); \
//         int ft_actual_ret = ft_printf(YELLOW format, ##__VA_ARGS__); \
//         printf("\n" RESET "printf:   " RESET); \
//         int std_actual_ret = printf(YELLOW format, ##__VA_ARGS__); \
//         printf(RESET "\nretours: ft_printf = %d, printf = %d\n\n", ft_actual_ret, std_actual_ret); \
//     } while(0)


// // COMPARE(
// //     "|%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c//%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c|",
// //     "' '!'\"'#'$'%'&'''('')'*''+','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','~'",
// //     ' ','!','"','#','$', '%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':', ';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U', 'V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p', 'q','r','s','t','u','v','w','x','y','z','{','|','~'
// // );
// // COMPARE("%%\n", "%%", '%');

// // COMPARE(
// //     "|%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c//%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c|",
// //     "' '!'\"'#'$','%','&','''','(',')','*','+','-', '.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','~'",
// //     ' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<', '=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u', 'v','w','x','y','z','{','|','~'
// // );

// char *str = "str";
// COMPARE("|%15p|", "NULL", str);
// COMPARE("|%15p|", "NULL", NULL);

// COMPARE("|%50c%-%|", "'i'", 105);  // '%' suivi de '-' est volontairement tordu

// 	COMPARE("|%c|", "'A'", 'A');
// 	COMPARE("|%s|", "\"Hello\"", "Hello");
// 	void *ptr = (void*)0x1234;
// 	COMPARE("|%p|", "ptr", ptr);
// 	COMPARE("|%x|", "0xabcdef", 0xabcdef);
// 	COMPARE("|%X|", "0xABCDEF", 0xabcdef);
// 	COMPARE("|%i|", "-42", -42);
// 	COMPARE("|%u|", "42", 42u);
// 	COMPARE("|%d|", "123", 123);
// 	COMPARE("|%c|", "'\\0'", 0);
// 	COMPARE("| %c %c %c |","0, '1', '2'", 0, '1', '2');

// 	printf("--- Test c (avec largeur et justification) ---\n");
//     COMPARE("|%5c|", "'A'", 'A');
//     COMPARE("|%-5c|", "'A'", 'A');
//     COMPARE("|%1c|", "'A'", 'A');

//     printf("--- Test s (avec largeur et justification) ---\n");
//     COMPARE("|%10s|", "\"Hello\"", "Hello");
//     COMPARE("|%-10s|", "\"Hello\"", "Hello");
//     COMPARE("|%3s|", "\"Hello\"", "Hello");
//     COMPARE("|%10s|", "\"\"", "");
//     COMPARE("|%-10s|", "\"\"", "");
//     COMPARE("|%10s|", "(char *)NULL", (char *)NULL);
//     COMPARE("|%-10s|", "(char *)NULL", (char *)NULL);

//     printf("--- Test s (avec précision) ---\n");
//     COMPARE("|%.3s|", "\"Hello\"", "Hello");
//     COMPARE("|%.0s|", "\"Hello\"", "Hello");
//     COMPARE("|%.5s|", "\"Hi\"", "Hi");
//     COMPARE("|%.s|", "(char *)NULL", (char *)NULL);
//     COMPARE("|%.0s|", "(char *)NULL", (char *)NULL);

//     printf("--- Test d et i (avec options) ---\n");
//     COMPARE("|%10d|", "123", 123);
//     COMPARE("|%-10d|", "123", 123);
//     COMPARE("|%010d|", "123", 123);
//     COMPARE("|%10d|", "-456", -456);
//     COMPARE("|%-10d|", "-456", -456);
//     COMPARE("|%010d|", "-456", -456);
//     COMPARE("|%5d|", "123456", 123456);
//     COMPARE("|%05d|", "123456", 123456);
//     COMPARE("|%i|", "0", 0);
//     COMPARE("|%10i|", "0", 0);
//     COMPARE("|%010i|", "0", 0);

//     printf("--- Test d et i (avec précision) ---\n");
//     COMPARE("|%.5d|", "123", 123);
//     COMPARE("|%.2d|", "12345", 12345);
//     COMPARE("|%10.5d|", "123", 123);
//     COMPARE("|%010.5d|", "123", 123);
	
//     printf("--- Test d et i (flags + et espace) ---\n");
//     COMPARE("|%+d|", "123", 123);
//     COMPARE("|%+d|", "-123", -123);
//     COMPARE("|% d|", "123", 123);
//     COMPARE("|% d|", "-123", -123);
//     COMPARE("|%+10d|", "123", 123);
//     COMPARE("|% 10d|", "123", 123);
	
//     printf("--- Test u (avec options) ---\n");
//     COMPARE("|%10u|", "123U", 123U);
//     COMPARE("|%010u|", "123U", 123U);
//     COMPARE("|%-10u|", "123U", 123U);
//     COMPARE("|%5u|", "987654U", 987654U);
//     COMPARE("|%05u|", "987654U", 987654U);
	
//     printf("--- Test u (avec précision) ---\n");
//     COMPARE("|%.5u|", "123U", 123U);
//     COMPARE("|%.2u|", "12345U", 12345U);
//     COMPARE("|%10.5u|", "123U", 123U);
//     COMPARE("|%010.5u|", "123U", 123U);
	
//     printf("--- Test x (avec options) ---\n");
//     COMPARE("|%10x|", "255U", 255U);
//     COMPARE("|%010x|", "255U", 255U);
//     COMPARE("|%-10x|", "255U", 255U);
//     COMPARE("|%4x|", "0xABC", 0xABC);
//     COMPARE("|%04x|", "0xABC", 0xABC);
	
//     printf("--- Test X (avec options) ---\n");
//     COMPARE("|%10X|", "255U", 255U);
//     COMPARE("|%010X|", "255U", 255U);
//     COMPARE("|%-10X|", "255U", 255U);
//     COMPARE("|%4X|", "0xABC", 0xABC);
//     COMPARE("|%04X|", "0xABC", 0xABC);
	
//     printf("--- Test x et X (avec précision) ---\n");
//     COMPARE("|%.5x|", "255U", 255U);
//     COMPARE("|%.2x|", "0xABC", 0xABC);
//     COMPARE("|%10.5x|", "255U", 255U);
//     COMPARE("|%010.5x|", "255U", 255U);
//     COMPARE("|%.5X|", "255U", 255U);
	
//     printf("--- Test x et X (flag #) ---\n");
//     COMPARE("|%#x|", "255U", 255U);
//     COMPARE("|%#X|", "255U", 255U);
//     COMPARE("|%#10x|", "255U", 255U);
	
//     printf("--- Test p ---\n");
//     COMPARE("|%p|", "(void *)0", (void *)0);
//     COMPARE("|%p|", "(void *)0x1234ABCD", (void *)0x1234ABCD);
//     COMPARE("|%15p|", "(void *)0x123", (void *)0x123);
//     COMPARE("|%-15p|", "(void *)0x123", (void *)0x123);
	
//     printf("--- Tests complexes et cas limites ---\n");
//     COMPARE("|%10.0s|", "\"Hello\"", "Hello");
//     COMPARE("|%-10.0s|", "\"Hello\"", "Hello");
//     COMPARE("|%20.5s|", "\"A very long string\"", "A very long string");
//     COMPARE("|%-20.5s|", "\"A very long string\"", "A very long string");
//     COMPARE("|%d|", "INT_MAX", INT_MAX);
//     COMPARE("|%d|", "INT_MIN", INT_MIN);
//     COMPARE("|%u|", "UINT_MAX", UINT_MAX);
//     COMPARE("|%#x|", "0xFFFFFFFFU", 0xFFFFFFFFU);
	
//     printf("--- Tests relous ---\n");
// 	COMPARE("|%.0u|", "0U", 0U);
//     COMPARE("|%.0x|", "0U", 0U);
//     COMPARE("|%.0X|", "0U", 0U);
//     COMPARE("|%#x|", "0U", 0U);
//     COMPARE("|%#X|", "0U", 0U);
//     COMPARE("|%#010x|", "255U", 255U);
//     COMPARE("|%+010d|", "123", 123);
//     COMPARE("|% 010d|", "123", 123);
// 	COMPARE("|%.0d|", "0", 0);
//     // COMPARE("|%+ d|", "123", 123);
//     // COMPARE("|%-010d|", "123", 123);
//     // COMPARE("Hello world", "No args", 0);
//     // COMPARE("|%%|", "No args", 0);
//     COMPARE("|%1c|", "\0", 0);
//     COMPARE("|%c|%1c|%2c|%3c|", "0, 0, 0", 0, 0, 0, 0);
//     COMPARE("|%-c|%-1c|%-2c|%-3c|", "0, 0, 0", 0, 0, 0, 0);
// 	COMPARE("|%%|", "");
// 	COMPARE("|%5%|", "");
// 	COMPARE("|%-5%|", "");
// 	COMPARE("|%-05%|", "");
// printf("--- Tests logs ---\n");

    return 0;
}