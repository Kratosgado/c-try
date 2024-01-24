#if !defined(RECTANGLE_H)
#define RECTANGLE_H

class Rectangle {
private:
   double width;
   double length;
public:
   // Exception class for a negative width
   class NegativeWidth {
   private:
      double value;
   public:
      NegativeWidth(double val) { value = val; }
      double getValue() const { return value; }
   };

   // Exception class for a negative length
   class NegativeLength {
   private:
      double value;
   public:
      NegativeLength(double val) {
         value = val;
      }
      double getValue() const {
         return value;
      }
   };
   // default constructor
   Rectangle() { width = 0.0;  length = 0.0; }
   // constructor #2
   Rectangle(double w, double len) { width = w;  length = len; }

   // mutator functions: defined in Rectangle.cpp
   void setWidth(double);
   void setLength(double);
   
   // accessor funcitons
   double getWidth() const { return width; }
   double getLength() const { return length; }
   double getArea() const { return width * length; }
};

#endif // RECTANGLE_H
