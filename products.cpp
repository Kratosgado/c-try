#include <iostream>
#include <string>
#include <vector>

using namespace std;
//declare size of all the arrays as a constant
const int SIZE = 9;
//function that prompts the user to enter an id
int getID(){
    int id;
    cout<<"Enter the Id of the product you want to search: ";
    cin>>id;
    return id;
}
//function that uses binary search to find id entered by the user
int getProduct(int array[], int size, int id){
    int begin=0,
        end = size-1,
        mid = -1;
    bool found = false;

        while (!found && begin<= end)
        {
            mid = (begin + end)/2;
            if (array[mid] == id){
                found = true;
                return mid;
            }
            if (array[mid]<id)
            {
                begin = mid;
            }
            else{
                end = mid;
            }
        }
    return -1;
        
}
//function that displays to the screen the title, description and price of the searched id
void showProduct(string title[], string description[], double price[], int index){
    string name = title[index];
    string type = description[index];
    double cost = price[index];

    cout<<"You searched for: "<<endl;
    cout<<"title: "<<name<<endl;
    cout<<"description: "<<type<<endl;
    cout<<"price: "<<cost<<endl;
    system("pause");
}
//main function
int main(){
    //initialize the lists of products with their id, title, description and price
   int id[SIZE] = {914, 915, 916, 917, 918, 919, 920, 921, 922};
   string title[SIZE] = {"Six steps to leadership", "Six steps to leadership", "The road to excellence",
   "Seven lessons of Quality", "Seven lessons of Quality", "Teams are made, not born", "Leadership for the future",
   "Leadership for the future"}; 
   string description[SIZE] = {"book", "Audio cd", "DVD", "book", "Audio CD", "DVD", "book", "book", "Audio CD"};
   double prices[SIZE] = {12.95, 14.95, 18.95, 16/95, 21.95, 31.95, 14.95, 14.95, 16.95};

    int search_id, product;
   do
   {
    search_id = getID();
   } while (search_id <id[0] and search_id > id[SIZE - 1]);

   product = getProduct(id, SIZE, search_id);

   showProduct(title, description, prices, product);
}