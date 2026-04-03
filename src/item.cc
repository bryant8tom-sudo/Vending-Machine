#include "item.hpp"

Item::Item(const std::string& name, double price): name_(name), price_(price) {}
double Item::GetPrice() const { return price_; }
std::string Item::GetName() const { return name_; }