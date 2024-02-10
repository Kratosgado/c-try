#include "Inventory.hpp"
#include <fstream>

void Inventory::load() {
   InventoryItem weapon;

   std::cout << "Loading weapons. \nPlease wait..." << std::endl;
   // open the file in binary mode for input
   std::ifstream inventory("Inventory.dat", std::ios::in | std::ios::binary);

   // test for errors
   if (!inventory) {
      std::cout << "TLoading failed.\nThere's no saved weapons.\n";
      return;
   }
   // read the first record form the file
   inventory.read(reinterpret_cast<char*>(&weapon), sizeof(weapon));

   // while not at the end of the file, display the records
   while (!inventory.eof()) {
      this->weapons[weapon.name] = weapon;

      // read the next record from the file
      inventory.read(reinterpret_cast<char*>(&weapon), sizeof(weapon));
   }
   std::cout << "Weapons loaded successfully" << std::endl;
   inventory.close();
   return;
}

void Inventory::save() {
   std::cout << "Saving weapons. \nPlease wait..." << std::endl;
   // open the file in binary mode for output
   std::ofstream inventory("Inventory.dat", std::ios::out | std::ios::binary);
   for (auto map : this->weapons) {
      inventory.write(reinterpret_cast<char*>(&map.second), sizeof(map.second));
   }
   inventory.close();
   std::cout << "Weapons saved successfully" << std::endl;
   return;
}

void Inventory::add(std::string wp, int amount) {
   InventoryItem weapon;
   // check if the weapon is inthe inventory and add the amount
   if (this->weapons.find(wp) != weapons.end()) {
      weapon = this->weapons[wp];
      weapon.qty += amount;
   }
   else {
      weapon.name = wp;
      weapon.qty = amount;
      this->weapons[wp] = weapon;
   }
   std::cout << "You added " << amount << " to " << wp
      << "\n" << wp << " is now " << weapon.qty << std::endl;
   return;
}

void Inventory::remove(std::string wp, int amount) {
   InventoryItem weapon;
   if (this->weapons.find(wp) != this->weapons.end()) {
      weapon = this->weapons[wp];
      if (weapon.qty - amount < 0) {
         std::cout << "Operation failed. You only have " << weapon.qty << " left" << std::endl;
         return;
      }
      weapon.qty -= amount;
      std::cout << amount << " removed from " << wp << ". \n You now have " << weapon.qty << " left" << std::endl;
      return;
   }
   std::cout << "Item not in inventory" << std::endl;
}

void Inventory::display() const {
   std::cout << "displaying weapons in inventory" << std::endl;
   for (auto map : this->weapons) {
      std::cout << map.second.name << ": "
         << map.second.qty << std::endl;
   }
}