#pragma once

#include "Inventory.hpp"
#include "Product.hpp"
#include "VendingMachineState.hpp"
#include "Note.hpp"
#include "Coin.hpp"
#include<iostream>


class VendingMachine{
  private:
    static VendingMachine *instance;
    Inventory *inventory;
    int totalPayment;
    Product *selectedProduct;
    VendingMachineState currentState;
 
  private: 
   VendingMachine(){
     this->inventory = new Inventory();
     this->currentState=SELECTPRODUCT;
     this->totalPayment=0;
     this->selectedProduct=NULL;
   }  

   public:
     static VendingMachine* getInstance(){
        if(instance==NULL){
            instance = new VendingMachine();
        }
        return instance;
     }

     Inventory* getInventory(){
      return inventory;
     }

     void selectProduct(Product *P){
       if(currentState!=SELECTPRODUCT){
          std::cout<<"Please finish previous transaction first\n";
          return; 
       }
       if(inventory->isAvailable(P)){
          setSelectProduct(P);
          inventory->updateQuantity(P,inventory->getQuantity(P)-1);
          setCurrentState(PAYMENT);
          std::cout<<"Your Product has been selected "<<P->getName()<<". ";
          std::cout<<"Please do the payment\n";
       }else{
         std::cout<<"Product is not available, Sorry!! \n";
       }
     }
     
     void ProcessPayment(){
       if(currentState!=PAYMENT){
         std::cout<<"Please finish previous transaction first\n";
         return;
       }
       if(getTotalPayment()>=selectedProduct->getPrice()){
          std::cout<<"Payment has been done "<<"please collect your product\n";
          setCurrentState(DISPENSEPRODUCT);
       }
     }
    
     void dispenseProduct(){
        if(currentState!=DISPENSEPRODUCT){
         std::cout<<"Please finish previous transaction first\n";
         return;
       }
       std::cout<<"Your Product has been dispensed "<<selectedProduct->getName()<<"\n";
       setCurrentState(RETURNCHANGE);
     }

     void returnChange(){
         if(currentState!=RETURNCHANGE){
         std::cout<<"Please finish previous transaction first\n";
         return;
         }
         if(getTotalPayment() > selectedProduct->getPrice()){
         int change = getTotalPayment() - selectedProduct->getPrice();
         std::cout<<"Please have your returned change "<<change<<"\n";
         }else{
         std::cout<<"No change is required to return\n";
         }
         resetPayment();
         resetSelectedProduct();
         setCurrentState(SELECTPRODUCT);
     }

     void setCurrentState(VendingMachineState state){
       currentState=state;
     }  
    
     void setSelectProduct(Product *P){
         selectedProduct=P;
     }

     Product *getSelectedProduct(){
        return selectedProduct;
     }

    void resetSelectedProduct() {
        selectedProduct = NULL;
    }

    int getTotalPayment() {
        return totalPayment;
    }

    void addCoin(Coin *coin) {
        totalPayment += coin->getValue();
    }

    void addNote(Note *note) {
        totalPayment += note->getValue();
    }

    void resetPayment() {
        totalPayment = 0.0;
    }
};

VendingMachine* VendingMachine::instance=NULL; 
