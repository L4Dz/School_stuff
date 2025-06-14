//
// Created by ladie on 07/06/2025.
//
const char* longest(const char* pa[]) {
    int n = 0;
    const char *longest = nullptr;
    for (int i=0; pa[i]!=nullptr; i++) {
        int temp = 0;
        for (int j=0; pa[i][j]!='\0'; j++) {
            ++temp;
        }
        if (temp >= n) {
            n = temp;
            longest=pa[i];
        }
    }
    return longest;
}