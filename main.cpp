//Ezzat Mohamadein | ComSc 210 | Final 2
#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

//consts
const int ROUNDS = 10;
const int JOIN = 50;
const int START = 2;

//coffee booth linked list struct
struct coffeeOrder
{
    string name;
    string order;
    coffeeOrder* next;
};

//muffin booth deque struct
struct muffinOrder
{
    string name;
    string order;
    muffinOrder* next;
};

//frienfship bracelet vector struct
struct bracelet
{
    string name;
    string fr;
};

int main()
{
    //names and drinks to be picked randomly for orders
    string names[] = {"Ali", "Mark", "John", "Bob", "Joe", "Nate", "Will", "Ethan"};
    string drinks[] = {"Latte", "Cappuccino", "Flat White", "Americano", "Espresso"};
    string muffins[] = {"Blueberry", "Strawberry", "Chocolate Chip", "Vanilla", "Pumpkin"};
    //set random seed
    srand(time(0));

    //create head node
    coffeeOrder* head = new coffeeOrder;
    head->name = names[rand() % 8];
    head->order = drinks[rand() % 5];
    //create randomised linked list with 3 customers and their orders
    coffeeOrder* tail = head;
    for (int i = 0; i < START; i++)
    {
        coffeeOrder* newNode = new coffeeOrder;
        newNode->name = names[rand() % 8];
        newNode->order = drinks[rand() % 5];
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }

    //create muffin deque
    muffinOrder* muffinHead = new muffinOrder;
    muffinHead->name = names[rand() % 8];
    muffinHead->order = muffins[rand() % 5];
    muffinHead->next = nullptr;
    muffinOrder* muffinTail = muffinHead;
    for (int i = 0; i < START; i++)
    {
        muffinOrder* newNode = new muffinOrder;
        newNode->name = names[rand() % 8];
        newNode->order = muffins[rand() % 5];
        newNode->next = nullptr;
        muffinTail->next = newNode;
        muffinTail = newNode;
    }

    //create bracelet vector
    vector<bracelet> bracelets;
    for (int i = 0; i < 8; i++)
    {
        bracelet newBracelet;
        newBracelet.name = names[i];
        newBracelet.fr = names[rand() % 8];
        bracelets.push_back(newBracelet);
    }

    //run simulation, 10 rounds, 50% of customer joining each round, first in line is always served
    for (int i = 0; i < ROUNDS; i++)
    {
        //display round
        cout << endl << "Round " << i + 1 << ": " <<endl;
        
        //if customer joins coffee booth
        if (rand() % 100 < JOIN)
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

        //customer joins muffin booth
        if (rand() % 100 < JOIN)
        {
            //create new node
            muffinOrder* newNode = new muffinOrder;
            newNode->name = names[rand() % 8];
            newNode->order = muffins[rand() % 5];
            newNode->next = nullptr;
            muffinTail->next = newNode;
            muffinTail = newNode;
            //print
            cout << newNode->name << " joined the coffee queue." << endl;
        }

        //customer joins bracelet booth
        if (rand() % 100 < JOIN)
        {
            //create new node
            bracelet newBracelet;
            newBracelet.name = names[rand() % 8];
            newBracelet.fr = names[rand() % 8];
            bracelets.push_back(newBracelet);
            //print
            cout << newBracelet.name << " joined the bracelet booth." << endl;
        }

        //check if coffee queue if empty
        if (head->next == nullptr)
        {
            cout << "The coffee queue is empty." << endl;
        }
        else {
            //serve head
            coffeeOrder* temp = head;
            head = head->next;
            cout << temp->name << " ordered: " << temp->order << "." << endl;
            delete temp;

            //print remaining queue
            coffeeOrder* current = head;
            cout << endl << "Coffee Queue:" << endl;
            while (current != nullptr)
            {
                cout << current->name << endl;
                current = current->next;
            }
            cout << endl;
        }

        //check if muffin queue is empty
        if (muffinHead->next == nullptr)
        {
            cout << "The muffin queue is empty." << endl;
        }
        else {
            //serve head
            muffinOrder* temp = muffinHead;
            muffinHead = muffinHead->next;
            cout << temp->name << " ordered: " << temp->order << "." << endl;
            delete temp;

            //print remaining queue
            muffinOrder* current = muffinHead;
            cout << endl << "Muffin Queue:" << endl;
            while (current != nullptr)
            {
                cout << current->name << endl;
                current = current->next;
            }
            cout << endl;
        }

        //check if bracelet vector is empty
        if (bracelets.size() == 0)
        {
            cout << "The bracelet booth is empty." << endl;
        }
        else {
            //serve head
            bracelet temp = bracelets[0];
            bracelets.erase(bracelets.begin());
            cout << temp.name << " gets a bracelet for: " << temp.fr << endl;

            //print remaining vector
            cout << endl << "Bracelet Booth:" << endl;
            for (int i = 0; i < bracelets.size(); i++)
            {
                cout << bracelets[i].name << endl;
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

    //delete muffin deque
    muffinOrder* currentm = muffinHead;
    while (currentm != nullptr)
    {
        muffinOrder* temp = currentm;
        currentm = currentm->next;
        delete temp;
    }

    //delete bracelet vector
    for (int i = 0; i < bracelets.size(); i++)
    {
        delete &bracelets[i];
    }

    return 0;
}