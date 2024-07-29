#pragma once

#include "Product.hpp"
#include<map>

class Inventory{
  private:
    std::map<Product*,int> products;
  public:
    Inventory(){}

    void addProduct(Product *p){
      products[p]++;
    }

    void removeProduct(Product *p){
      products.erase(p);  
    }

    void updateQuantity(Product *p,int q){
        products[p]=q;
    }

    int getQuantity(Product *p){
        return products[p];
    } 

    bool isAvailable(Product *p){
        return products[p]>0;
    }
};