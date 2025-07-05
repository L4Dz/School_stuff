#include "ResaleProduct.h"

ResaleProduct::ResaleProduct(int id, float price, int profit_margin_):
    Product(id, price), profit_margin(profit_margin_) {}

int ResaleProduct::get_profit_margin() const {
    return profit_margin;
}

void ResaleProduct::set_profit_margin(int margin) {
    profit_margin = margin;
}

float ResaleProduct::get_sell_price() const {
    return price_ * (100.0f + profit_margin) / 100.0f;
}