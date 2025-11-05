int compare_strings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}
