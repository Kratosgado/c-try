// SimpleVector class template
#if !defined(SIMPLEVECTOR_H)
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>  // needed of r bad_alloc exception
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector {
private:
   T* aptr;   // To point to the allocated array
   int arraySize;
   void memError();  // handles memory allocation errors
   void subError(); // handles subscripts out or range

public:
   // default constructor
   SimpleVector() { aptr = 0;  arraySize = 0; }
   // constructor declaration
   SimpleVector(int);

   // copy constructor declaration
   SimpleVector(const SimpleVector&);

   // destructor
   ~SimpleVector();

   // Accessor to return the array size
   int size() const { return arraySize; }
   // Accessor to return a specific element
   T getElementAt(int position);

   // overloaded[] operator declaration
   T& operator[](const int&);
};

template <class T>
SimpleVector<T>::SimpleVector(int s) {
   arraySize = s;
   // allocate memory for the array.
   try {
      aptr = new T[s];
   }
   catch (bad_alloc) {
      memError();
   }
   // initialize the array
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj) {
   // copy the array size.
   arraySize = obj.arraySize;

   // allocate memory for the array
   aptr = new T[arraySize];
   if (aptr == 0) memError();
   // Copy the elements of obj's array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

template <class T>
SimpleVector<T>::~SimpleVector() {
   if (arraySize > 0) {
      delete[] aptr;
   }
}

template <class T>
void SimpleVector<T>::memError() {
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//************************************************************
// subError function. Displays an error message and          *
// terminates the program when a subscript is out of range.  *
//************************************************************
template <class T>
void SimpleVector<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
T SimpleVector<T>::getElementAt(int sub) {
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//********************************************************
// Overloaded [] operator. The argument is a subscript.  *
// This function returns a reference to the element      *
// in the array indexed by the subscript.                *
//********************************************************
template <class T>
T& SimpleVector<T>::operator[](const int& sub) {
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

#endif // SIMPLEVECTOR_H
