#include "dispenser.hpp"
#include "item.hpp"
#include <stdexcept>

Dispenser::Dispenser(int maxCapacity) {
    max_capacity_ = maxCapacity;
    count_ = 0;
    
    items_ = new Item*[max_capacity_];
    
    for (int i = 0; i < max_capacity_; ++i) {
        items_[i] = nullptr;
    }
}

Dispenser::~Dispenser() {
    for (int i = 0; i < count_; ++i) {
        delete items_[i];
        items_[i] = nullptr; 
    }
    
    delete[] items_;
    items_ = nullptr;
}

// 3. AddItem
void Dispenser::AddItem(const std::string& name, double price) {
    if (count_ >= max_capacity_) {
        throw std::runtime_error("Dispenser is full.");
    }
    
    items_[count_] = new Item(name, price);
    
    count_++;
}

// 4. Vend
Item* Dispenser::Vend() {
    if (count_ == 0) {
        throw std::runtime_error("Dispenser is empty.");
    }
    
    Item* vended_item = items_[0];
    
    ShiftItemsLeft();
    
    count_--;
    
    items_[count_] = nullptr;
    
    return vended_item;
}
//Debug this function!
void Dispenser::ShiftItemsLeft() {
  for (int i = 0; i < count_ - 1; ++i) {
    items_[i] = items_[i + 1];
  }
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
