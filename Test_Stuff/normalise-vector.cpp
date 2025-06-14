//
// Created by ladie on 10/06/2025.
//
#include <vector>
#include "print_vector.h"
using namespace std;
// pensar nesse mambo como se fosse um place holder e outra cena, tenho de rever pointers bem
template <typename T>
void normalise(vector<T>& v, const T& min, const T& max) {
    for (T& element : v) {
        if (element < min) {
            element = min;
        } else if (element > max) {
            element = max;
        }
    }
}