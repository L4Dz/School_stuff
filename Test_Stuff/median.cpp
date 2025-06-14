//
// Created by ladie on 06/06/2025.
//
#include <algorithm>
#include <iostream>



int median(const int a[], int n) {

    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i];
    }
    std::sort(temp, temp + n);
    int final;
    if (n % 2 == 0) {
        final = (temp[ n / 2 - 1] + temp[ n / 2]) / 2;
    }
    else {
        final = temp[ n / 2];
    }
    delete [] temp;
    return final;
}

