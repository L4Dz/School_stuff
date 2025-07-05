#ifndef RESALEPRODUCT_H
#define RESALEPRODUCT_H
#include "Product.h"

class ResaleProduct : public Product {
private: 
    int profit_margin;
public:
    ResaleProduct(int id, float price, int profit_margin_);  // float price
    int get_profit_margin() const;
    float get_sell_price() const override;
    void set_profit_margin(int margin);  // Different parameter name
};

#endif //RESALEPRODUCT_H