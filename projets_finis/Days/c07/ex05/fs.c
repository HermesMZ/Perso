#include <stdlib.h>

char *ft_strndup(const char *str, int size) {
    if (!str || size <= 0) {
        return NULL;
    }
    char *tmp = malloc(size + 1);
    if (!tmp) {
        return NULL;
    }
    int i = 0;
    while (i < size) {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}

int is_charset(char c, const char *charset) {
    int i = 0;
    while (charset[i]) {
        if (charset[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

int strings_count(const char *str, const char *charset) {
    int count = 0;
    int in_word = 0;
    int i = 0;
    while (str[i]) {
        if (!is_charset(str[i], charset) && !in_word) {
            count++;
            in_word = 1;
        } else if (is_charset(str[i], charset)) {
            in_word = 0;
        }
        i++;
    }
    return count;
}

char **ft_split(const char *str, const char *charset) {
    if (!str || !charset) {
        return NULL;
    }
    int count = strings_count(str, charset);
    char **result = malloc((count + 1) * sizeof(char *));
    if (!result) {
        return NULL;
    }
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (!is_charset(str[i], charset)) {
            int start = i;
            while (str[i] && !is_charset(str[i], charset)) {
                i++;
            }
            result[j] = ft_strndup(&str[start], i - start);
            if (!result[j]) {
                // Gestion de l'erreur : libérer la mémoire et retourner NULL
                while (j > 0) {
                    free(result[--j]);
                }
                free(result);
                return NULL;
            }
            j++;
        } else {
            i++;
        }
    }
    result[j] = NULL;
    return result;
}