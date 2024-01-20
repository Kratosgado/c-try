// This program demonstrates a simple class
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

// main function
int main() {
   Rectangle box;
   double rectWidth;
   double rectLenght;

   // get the rectangle's width and length from the user.
   cout << "This program will calculate the area of a\n";
   cout << "rectangle. What is the width? ";
   cin >> rectWidth;
   cout << "What is the length? ";
   cin >> rectLenght;

   // store the width and length of the rectangle in the box object
   box.setWidth(rectWidth);
   box.setLength(rectLenght);

   // Display the rectangle's data.
   cout << "Here is the rectangle's data:\n";
   cout << "Width: " << box.getWidth() << endl;
   cout << "Length: " << box.getLength() << endl;
   cout << "Area: " << box.getArea() << endl;
   return 0;
}