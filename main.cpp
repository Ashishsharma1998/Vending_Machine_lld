#include "VendingMachine.hpp"
#include "Product.hpp"
#include "Inventory.hpp"
#include "NoteAndCoin.hpp"

int main(){
  VendingMachine *vm = VendingMachine::getInstance();
 
  //create product
  Product *p1 = new Product("coke",10);
  Product *p2 = new Product("parleG",10);
  Product *p3 = new Product("Waffers",30);

  //add it to inventory 
  vm->getInventory()->addProduct(p1);
  vm->getInventory()->addProduct(p2);
  vm->getInventory()->addProduct(p3);

  //Lets purchase a product

  //select a product
  vm->selectProduct(p1);
  
  //do payment
  vm->addCoin(new Coin(TEN));

  vm->ProcessPayment();

  //dispense product
  vm->dispenseProduct();

  //if any change then return
  vm->returnChange();

  return 0;  
}