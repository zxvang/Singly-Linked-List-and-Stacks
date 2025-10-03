// Zajkub Vang

#include "Headers.h"

int main()
{
    LinkedList myList;
    myList.push_back(10);
    myList.push_front(5);
    myList.insert(1, 7);
    myList.print(); // Output: 5 7 10

    myList.pop_front();
    myList.print(); // Output: 7 10

    myList.pop_back();
    myList.print(); // Output: 7

    size_t idx = myList.find(7);
    cout << "Index of 7: " << idx << std::endl;

    Numbers n1;
    Numbers n2(42);
    cout << "n1: " << n1.getNum() << ", n2: " << n2.getNum() << std::endl;

    cout << "Main Menu:";
    
}
// End of file Main.cpp