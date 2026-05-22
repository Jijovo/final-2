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

    //create head node
    coffeeOrder* head = new coffeeOrder;
    head->name = names[rand() % 8];
    head->order = drinks[rand() % 5];
    //create randomised linked list with 3 customers and their orders
    coffeeOrder* tail = head;
    for (int i = 0; i < 3; i++)
    {
        coffeeOrder* newNode = new coffeeOrder;
        newNode->name = names[rand() % 8];
        newNode->order = drinks[rand() % 5];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }

    //run simulation, 10 rounds, 50% of customer joining each round, first in line is always served
    for (int i = 0; i < 10; i++)
    {
        //display round
        cout << endl << "Round " << i + 1 << ": " <<endl;
        
        //if customer joins
        if (rand() % 100 < 50)
        {
            //create new node
            coffeeOrder* newNode = new coffeeOrder;
            newNode->name = names[rand() % 8];
            newNode->order = drinks[rand() % 5];
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
            //print
            cout << newNode->name << " joined the queue." << endl;
        }

        //check if queue if empty
        if (head->next == nullptr)
        {
            cout << "The queue is empty." << endl;
        }
        else {
            //serve head
            coffeeOrder* temp = head;
            head = head->next;
            cout << temp->name << " is served." << endl;
            delete temp;

            //print remaining queue
            coffeeOrder* current = head;
            cout << endl << "Queue:" << endl;
            while (current != nullptr)
            {
                cout << current->name << endl;
                current = current->next;
            }
            cout << endl;
        }
    }

    //delete linked list
    coffeeOrder* currentd = head;
    while (currentd != nullptr)
    {
        coffeeOrder* temp = currentd;
        currentd = currentd->next;
        delete temp;
    }

    return 0;
}