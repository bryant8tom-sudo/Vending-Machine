#ifndef DISPENSER_HPP
#define DISPENSER_HPP
#include <stdexcept>

#include "item.hpp"

class Dispenser {
public:
  Dispenser() = default;
  Dispenser(int maxCapacity);  // TODO
  ~Dispenser();                // TODO
  Dispenser(const Dispenser& other) = delete;
  Dispenser& operator=(const Dispenser& other) = delete;
  void AddItem(const std::string& name, double price);  // TODO
  Item* Vend();                                         // TODO
  void ShiftItemsLeft(); // DEBUG
  int GetCount() const;
  int GetMaxCapacity() const;
  int GetRemainingCapacity() const;
  bool IsEmpty() const;
  bool IsFull() const;
  Item* Peek() const;

private:
  Item** items_;
  int count_ = 0;
  int max_capacity_ = 0;
};
#endif