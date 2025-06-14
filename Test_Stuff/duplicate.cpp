//
// Created by ladie on 06/06/2025.
//
char* duplicate(const char s[]) {
    int size = 0;
    for (int i=0; s[i] != '\0'; i++) {
        size++;
    }
    char* final = new char[size-1];
    for (int i = 0; i < size; i++) {
        final[i] = s[i];
    }
    return final;
}