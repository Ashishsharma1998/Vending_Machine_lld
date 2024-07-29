#pragma once

#include "NoteAndCoin.hpp"

class Coin{
  private:
    COIN value;
  public:
    Coin(COIN value){
        this->value = value;
    }  
    
    COIN getValue(){
        return value;
    }

};