// This program creates three instances of the rectangle class
#include <iostream>
using namespace std;

// Rectangle class declaration.
class Rectangle {
private:
   double width;
   double length;
public:
   void setWidth(double);
   void setLength(double);
   double getWidth() const;
   double getLength() const;
   double getArea() const;
};

void Rectangle::setWidth(double w) {
   width = w;
}
void Rectangle::setLength(double l) {
   length = l;
}
double Rectangle::getWidth() const { return width; }
double Rectangle::getLength() const { return length; }
double Rectangle::getArea() const { return width * length; }

int main() {
   double number;
   double totalArea;
   Rectangle* kitchen = nullptr; // to point to kitchen dimensions
   Rectangle* bedroom = nullptr;
   Rectangle* den = nullptr;

   // dynamically allocate the objects.
   kitchen = new Rectangle;
   bedroom = new Rectangle;
   den = new Rectangle;

   // get the kitchen dimensions.
   cout << "What is the kitchen's length? ";
   cin >> number;
   kitchen->setLength(number);
   cout << "What is the kitchen's width? ";
   cin >> number;
   kitchen->setWidth(number);

   // get the bedroom dimensions
   cout << "What is the bedroom's length? ";
   cin >> number;
   bedroom->setLength(number);
   cout << "What is the bedroom's width? ";
   cin >> number;
   bedroom->setWidth(number);

   // get the den dimensions
   cout << "What is the den's length? ";
   cin >> number;
   den->setLength(number);
   cout << "What is the den's width? ";
   cin >> number;
   den->setWidth(number);

   // calculate the total area of the three rooms.
   totalArea = kitchen->getArea() + bedroom->getArea() + den->getArea();

   // display the total area of the three rooms.
   cout << "The total area of the three rooms is " << totalArea << endl;

   // delete the objects from memory.
   delete kitchen;
   delete bedroom;
   delete den;
   kitchen = nullptr;
   bedroom = nullptr;
   den = nullptr;

   return 0;
}