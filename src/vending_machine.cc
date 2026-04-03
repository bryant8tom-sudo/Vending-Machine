#include "vending_machine.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

VendingMachine::VendingMachine(const std::string& filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::runtime_error("Could not open file.");
  }

  ifs >> rows_ >> cols_;
  ifs >> max_dispenser_size_;

  dispensers_ = new Dispenser**[rows_];
  for (int r = 0; r < rows_; ++r) {
    dispensers_[r] = new Dispenser*[cols_];
    for (int c = 0; c < cols_; ++c) {
      dispensers_[r][c] = nullptr;
    }
  }

  std::string name;
  int row, col, quantity;
  double price;
  
  while (ifs >> std::quoted(name) >> row >> col >> price >> quantity) {
    Restock(name, row, col, price, quantity);
  }
}
// Debug this function!
VendingMachine::~VendingMachine() {
  if (dispensers_ == nullptr) return;
  
  for (int i = 0; i < rows_; ++i) {
    if (dispensers_[i] != nullptr) {
      for (int j = 0; j < cols_; ++j) {
        delete dispensers_[i][j];
      }
      delete[] dispensers_[i];
    }
  }
  delete[] dispensers_;
}

void VendingMachine::AddItem(int row, int col, const std::string& name, double price) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::runtime_error("Invalid row or column.");
  }

  if (dispensers_[row][col] == nullptr) {
    dispensers_[row][col] = new Dispenser(max_dispenser_size_);
  }

  dispensers_[row][col]->AddItem(name, price);
}

Item* VendingMachine::Vend(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_ || dispensers_[row][col] == nullptr) {
    throw std::runtime_error("Invalid location or dispenser does not exist.");
  }

  Item* vended_item = dispensers_[row][col]->Vend();

  if (dispensers_[row][col]->IsEmpty()) {
    delete dispensers_[row][col];
    dispensers_[row][col] = nullptr;
  }

  return vended_item;
}
void VendingMachine::Restock(const std::string& name, int row, int col, double price, int quantity) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_ || dispensers_[row][col] != nullptr) {
    throw std::runtime_error("Invalid location or dispenser already exists.");
  }

  if (quantity > max_dispenser_size_) {
    throw std::runtime_error("Quantity exceeds maximum dispenser capacity.");
  }

  dispensers_[row][col] = new Dispenser(max_dispenser_size_);
  for (int i = 0; i < quantity; ++i) {
    dispensers_[row][col]->AddItem(name, price);
  }
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
