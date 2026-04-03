// main.cc
#include <fstream>
#include <iostream>

#include "vending_machine.hpp"

int main() {
    std::cout << "Constructing vending machine" << std::endl;
    VendingMachine vendingMachine("sample/vending_machine.txt");
    // print out the resulting vending machine
    vendingMachine.DisplayItems();

    std::cout << "\nrestock an empty location with chocolate" << std::endl;
    vendingMachine.Restock("Chocolate",3,1,2.0,2);
    vendingMachine.DisplayItems();
    std::cout << std::endl;

    std::cout << "\nvend a single cookies item" << std::endl;
    Item* cookie = vendingMachine.Vend(1,1);
    delete cookie;
    vendingMachine.DisplayItems();

    std::cout << "\nvend another cookies item, dispenser is emptied" << std::endl;
    cookie = vendingMachine.Vend(1,1);
    delete cookie;
    vendingMachine.DisplayItems();

    std::cout << "\nrestock a new item in the emptied location" << std::endl;
    vendingMachine.Restock("Candy",1,1,1.75,2);
    vendingMachine.DisplayItems();
   
}