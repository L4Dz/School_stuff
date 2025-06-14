//
// Created by ladie on 06/06/2025.
//

#ifndef ALIST_H
#define ALIST_H
#include <iostream>
#include <cstdarg>

//! Array list.
struct alist {
    int size;       // Number of elements.
    int* elements;  // List elements.
};

//! Build an empty list.
alist* empty() {
    return new alist { 0, nullptr };
}

//! Build array list.
alist* build(int n, int v[]) {
    alist* al = new alist;
    al->size = n;
    if (n == 0) {
        al->elements = nullptr;
    } else {
        al->elements = new int[n];
        for (int i = 0; i < n; i++) {
            al->elements[i] = v[i];
        }
    }
    return al;
}

//! Destroy array list
void destroy(const alist* al) {
    delete [] al->elements;
    delete al;
}

void print(const alist* al) {
    std::cout << '[';
    for (int i = 0; i < al->size; i++) {
        std::cout << ' ' << al->elements[i];
    }
    std::cout << " ]\n";
}

//! Append function (declaration only, must be implemented).
void append(alist* a, const alist* b) {
    if (b->size == 0) {
        return;
    }

    int total_size = a->size + b->size;
    int* final = new int[total_size];
    int index = 0;
    for (int i = 0; i < a->size; i++) {
        final[index++]=a->elements[i];
    }
    for (int i = 0; i < b->size; i++) {
        final[index++]=b->elements[i];
    }

    if (a->elements != nullptr) {
        delete[] a->elements;
    }

    a->elements = final;
    a->size = total_size;
}
#endif //ALIST_H
