//Ezzat Mohamadein | ComSc 210 | Final 2
#include <iostream>
#include <string>
using namespace std;

//coffee booth linked list struct
struct coffeeOrder
{
    string name;
    string order;
    coffeeOrder* next;
};

int main()
{
    //names and drinks to be picked randomly for orders
    string names[] = {"Ali", "Mark", "John", "Bob", "Joe", "Nate", "Will", "Ethan"};
    string drinks[] = {"Latte", "Cappuccino", "Flat White", "Americano", "Espresso"};
    //set random seed
    srand(time(0));

    //create randomised linked list
    coffeeOrder* head = nullptr;
    for (int i = 0; i < 8; i++)
    {
        coffeeOrder* newNode = new coffeeOrder;
        newNode->name = names[rand() % 8];
        newNode->order = drinks[rand() % 5];
        newNode->next = head;
        head = newNode;
    }

    //print the linked list
    coffeeOrder* current = head;
    while (current != nullptr)
    {
        cout << current->name << " ordered: " << current->order << endl;
        current = current->next;
    }
    return 0;
}