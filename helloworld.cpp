#include <iostream>

using namespace std;

int main(){
    char contin = 'y';
    const int ADD = 1, SUBTRACT = 2, MULTIPLY = 3, DIVIDE = 4, MODULUS = 5;
    int choice, first_number, second_number; double result;
    do
    {
         cout<<"Menu:\n\t1. Add\n\t2. Subtract\n\t3. Multiply\n\t4. Divide\n\t5. Modulus\nEnter your choice: ";
    cin>>choice;
    cout<<"Enter your two numbers separated by space: ";
    cin>>first_number>>second_number;

        switch (choice)
        {
        case ADD:
            result = first_number + second_number;
            break;
        case SUBTRACT:
            result = first_number - second_number;
            break;
        case MULTIPLY:
            result = first_number * second_number;
            break;
        case DIVIDE:
            result = static_cast<double>(first_number)/second_number;
            break;
        case MODULUS:
            result = first_number % second_number;
            break;
        default:
            cout<<"You entered a wrong option";
            break;
        }
    cout<<result;
    system("PAUSE");
    cout<<"continue?(y/n): ";
    cin>>contin;
    } while (contin == 'y');
    
   
        
}