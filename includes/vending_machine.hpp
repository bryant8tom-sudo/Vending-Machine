#ifndef VENDING_MACHINE_HPP
#define VENDING_MACHINE_HPP
#include <string>

#include "dispenser.hpp"

class VendingMachine {
public:
  VendingMachine() = default;
  VendingMachine(const std::string& filename);  // TODO
  ~VendingMachine();                            // DEBUG
  VendingMachine(const VendingMachine& other) = delete;
  VendingMachine& operator=(const VendingMachine& other) = delete;
  void AddItem(int row,
               int col,
               const std::string& name,
               double price);    // TODO
  Item* Vend(int row, int col);  // TODO
  void Restock(const std::string& name,
               int row,
               int col,
               double price,
               int quantity);  // TODO
  int GetDispenserCapacity(int row, int col) const;
  void DisplayItems() const;
private:
  Dispenser*** dispensers_;
  int rows_ = 0;
  int cols_ = 0;
  int max_dispenser_size_ = 0;
};
#endif