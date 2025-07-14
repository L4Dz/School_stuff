//
// Created by ladie on 08/07/2025.
//

#include "Book.h"
#include "Page.h"
#include <set>
#include <string>
using namespace std;

void Book::build_index(const set<string>& words) {
    index_.clear(); // limpar index antes de começar

    int page_number = 1;
    for (const auto& page : page) {
        for (const auto& word : words) {
            if (page.contains(word)) {
                index_[word].insert(page_number);
            }
        }
        page_number++;
    }
}
