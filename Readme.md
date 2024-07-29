# Designing a Vending Machine

## Requirements

1. The vending machine should support multiple products with different prices and quantities.
1. The machine should accept coins and notes of different denominations.
1. The machine should dispense the selected product and return change if necessary.
1. The machine should keep track of the available products and their quantities.
1. The machine should handle multiple transactions concurrently and ensure data consistency.
1. The machine should provide an interface for restocking products and collecting money.
1. The machine should handle exceptional scenarios, such as insufficient funds or out-of-stock products.

## Implementations

### CPP Implementation

## Classes and Enumerations

1. The **Product** class represents a product in the vending machine, with properties such as name and price.
2. The **Coin** and **Note** enums represent the different denominations of coins and notes accepted by the vending machine.
3. The **Inventory** class manages the available products and their quantities in the vending machine.
4. The **VendingMachineState** enum defines the behavior of the vending machine in different states, such as SELECTPRODUCT, PAYMENT, and DISPENSE.
5. The **VendingMachine** class is the main class that represents the vending machine. It follows the Singleton pattern to ensure only one instance of the vending machine exists.
6. The VendingMachine class maintains the current state, selected product, total payment, and provides methods for state transitions and payment handling.
7. The **main.cpp** demonstrates the usage of the vending machine by adding products to the inventory, selecting products, inserting coins and notes, dispensing products, and returning change.
