#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <stdexcept>
#include <string>
class Item {
public:
  Item() = default;
  Item(const std::string& name, double price);
  double GetPrice() const;
  std::string GetName() const;

private:
  std::string name_;
  double price_ = 0.0;
};
#endif