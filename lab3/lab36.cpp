int count_vowels(char *str) {
    char *ptr = str;
    int count = 0;
    while (*ptr != '\0') {
        char c = tolower(*ptr);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        ptr++;
    }
    return count;
}
