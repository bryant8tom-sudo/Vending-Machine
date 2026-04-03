#include "vending_machine.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

VendingMachine::VendingMachine(const std::string& filename) {
  // TODO
}

// Debug this function!
VendingMachine::~VendingMachine() {
  for (int i = 0; i < rows_; ++i) {
    delete[] dispensers_[i];
  }
  delete[] dispensers_;
}

void VendingMachine::AddItem(int row,
                             int col,
                             const std::string& name,
                             double price) {
  // TODO
}

Item* VendingMachine::Vend(int row, int col) {
  // TODO
  return nullptr;
}
void VendingMachine::Restock(
    const std::string& name, int row, int col, double price, int quantity) {
  // TODO
}
int VendingMachine::GetDispenserCapacity(int row, int col) const {
  if (dispensers_[row][col] == nullptr) {
    return max_dispenser_size_;
  }
  return dispensers_[row][col]->GetRemainingCapacity();
}

void VendingMachine::DisplayItems() const {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      std::cout << "Position (" << i << "," << j << "): ";
      if (dispensers_[i][j] == nullptr) {
        std::cout << "[No Dispenser]\n";
      } else {
        const Item* item = dispensers_[i][j]->Peek();
        if (item) {
          std::cout << item->GetName() << " ($" << std::fixed
                    << std::setprecision(2) << item->GetPrice() << ") - "
                    << dispensers_[i][j]->GetCount() << " remaining\n";
        } else {
          std::cout << "[Empty Dispenser]\n";
        }
      }
    }
  }
}