#pragma once

#include<string>

class Product{
  private:
   std::string name;
   int price;
  public:
    Product(std::string name,int price){
      this->name=name;
      this->price=price;
    } 

    int getPrice(){
        return price;
    }

    std::string getName(){
        return name;
    }
};