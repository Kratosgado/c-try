/*
This is a class that stores weapons in and allows users to add or remove weapons from it.
It can be used in games or even apps

class inventory:
    add
    remove
    display
    save
    load

class main:
    instancing the  inventory class and calling it to run
*/

#if !defined(Inventory_H)
#define Inventory_H
#include <map>
#include <iostream>
#include <list>

struct InventoryItem {
   std::string name;
   int qty;
};

class Inventory {
private:
   std::map<std::string, InventoryItem> weapons;
public:
   Inventory() {
      // this->load();
   };

   void load();
   void save();
   void add(std::string weapon, int amt);
   void remove(std::string weapon, int amt);
   void display() const;
};

#endif // Inventory_H
