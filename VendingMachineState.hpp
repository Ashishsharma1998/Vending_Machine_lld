#pragma once

#include "Product.hpp"
#include "Coin.hpp"
#include "Note.hpp"

enum VendingMachineState{
   SELECTPRODUCT,
   PAYMENT,
   DISPENSEPRODUCT,
   RETURNCHANGE
};