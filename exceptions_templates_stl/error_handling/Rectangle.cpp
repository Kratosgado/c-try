// impl file for Rectangle class
#include "Rectangle.h"

void Rectangle::setWidth(double w) {
   if (w >= 0) width = w;
   else throw NegativeWidth(w);
}

void Rectangle::setLength(double l) {
   if (l >= 0) length = l;
   else throw NegativeLength(l);
}

