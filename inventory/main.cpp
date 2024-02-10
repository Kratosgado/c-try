#include "Inventory.hpp"

int main() {
   Inventory invent = Inventory();
   std::string cmd;


      // use a while loop to keep the program running forever
      while (true) {
         // get command
         std::cout << "Enter command: add, rem, list, save, load exit: ";
         std::cin >> cmd;
         std::cin.ignore();

         if (cmd == "add" || cmd == "rem")
         {
            std::string weapon; int qty;
            std::cout << " Enter the weapon: ";
            std::cin >> weapon;
            std::cout << "quantity: ";
            std::cin >> qty;
            cmd == "add" ? invent.add(weapon, qty) : invent.remove(weapon, qty);
         }
         else if (cmd == "list") invent.display();
         else if (cmd == "save") invent.save();
         else if (cmd == "load") invent.load();
         else if (cmd == "exit") {
            invent.save();
            invent.~Inventory();
            break;
         }

      }

}