// This program demonstrates passing arguments to a base class constructor
#include <iostream>
#include "Cube.h"
using namespace std;

int main() {
   double cubeWidth;
   double cubeLength;
   double cubeHeight;

   cout << "Enter the dimensions of a cube: \nWidth: "; cin >> cubeWidth;
   cout << "Length: "; cin >> cubeLength;
   cout << "Height: "; cin >> cubeHeight;

   Cube myCube(cubeWidth, cubeLength, cubeHeight);

   // Display the Cube object's properties.
   cout << "Here are the cube's properties:\n";
   cout << "Width: " << myCube.getWidth() << endl;
   cout << "Length: " << myCube.getLength() << endl;
   cout << "Height: " << myCube.getHeight() << endl;
   cout << "Base area: " << myCube.getArea() << endl;
   cout << "Volume: " << myCube.getVolume() << endl;
   return 0;

}