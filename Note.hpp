#pragma once

#include "NoteAndCoin.hpp"

class Note{
  private:
    NOTE value;
  public:
    Note(NOTE value){
        this->value = value;
    }  
    
    NOTE getValue(){
        return value;
    }

};