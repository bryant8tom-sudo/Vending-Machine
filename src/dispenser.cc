#include "dispenser.hpp"

Dispenser::Dispenser(int maxCapacity): count_(0), max_capacity_(maxCapacity) {
  // TODO
  
}

Dispenser::~Dispenser() {
  // TODO
}

void Dispenser::AddItem(const std::string& name, double price) {
  // TODO

}

Item* Dispenser::Vend() {
  // TODO
  return nullptr;
}
//Debug this function!
void Dispenser::ShiftItemsLeft() {
  items_[count_ - 1] = nullptr;
  for (int i = 0; i < count_ - 1; ++i) {
    items_[i] = items_[i + 1];
  }
  --count_;
}

Item* Dispenser::Peek() const {
  if (IsEmpty()) {
    return nullptr;
  }
  return items_[0];
}
int Dispenser::GetCount() const { return count_; }
int Dispenser::GetMaxCapacity() const { return max_capacity_; }
int Dispenser::GetRemainingCapacity() const { return max_capacity_ - count_; }
bool Dispenser::IsEmpty() const { return count_ == 0; }
bool Dispenser::IsFull() const { return count_ == max_capacity_; }