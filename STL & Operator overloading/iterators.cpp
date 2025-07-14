//
// Created by ladie on 08/07/2025.
//
#include <string>
#include<sstream>
#include<vector>
#include <list>
#include <iostream>



using namespace std;
template <typename Itr>
string to_string(Itr start, Itr end) {
    ostringstream os;//string os pra fazer saida usamos como se fosse o cout
    os<<"[ ";
    for (auto it = start; it!=end; ++it) {// essa é a forma correta de usar iteradores ;condição; ++itr1)
        os << *it<<" ";
    }
    os<<"]";
    string result = os.str();//temos de extrair
    return result;
}

template <typename Itr, typename T>
int replace_it(Itr start, Itr end, const T& a, const T& b) {
    int total = 0;
    for (auto it= start; it!=end; ++it) {
        if (*it == a) {
            *it = b;
            total++;
        }
    }
    return total;
}