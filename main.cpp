//Ezzat Mohamadein | ComSc 210 | Final 2
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>      // replaced <map> with <list>
using namespace std;

//consts
const int ROUNDS = 10;
const int JOIN = 50;
const int START = 2;
const int MAX = 1000;

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

//friendship bracelet vector struct
struct bracelet
{
    string name;
    string fr;
};

//console list struct
struct console
{
    string name;
    string console;
};

int main()
{
    //names and drinks to be picked randomly for orders
    string names[] = {"Ali", "Mark", "John", "Bob", "Joe", "Nate", "Will", "Ethan"};
    string drinks[] = {"Latte", "Cappuccino", "Flat White", "Americano", "Espresso"};
    string muffins[] = {"Blueberry", "Strawberry", "Chocolate Chip", "Vanilla", "Pumpkin"};
    string consoles[] = {"Xbox", "Playstation", "Nintendo", "PC", "Mobile"};
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
    for (int i = 0; i < START; i++)
    {
        bracelet newBracelet;
        newBracelet.name = names[i];
        newBracelet.fr = names[rand() % 8];
        bracelets.push_back(newBracelet);
    }

    //create list of consoles booth
    list<console> consolesBooth;
    for (int i = 0; i < START; i++)
    {
        console newConsole;
        newConsole.name = names[i];
        newConsole.console = consoles[rand() % 5];
        consolesBooth.push_back(newConsole);
    }

    //run simulation, 10 rounds, 50% of customer joining each round, first in line is always served
    for (int i = 0; i < ROUNDS; i++)
    {
        //display round
        cout << endl << "Round " << i + 1 << ": " <<endl;
        
        //check if coffee queue if empty
        if (head == nullptr)
        {
            cout << "The coffee queue is empty." << endl << endl;
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
            cout << "The muffin queue is empty." << endl << endl;
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
            cout << "The bracelet booth is empty." << endl << endl;
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
        
        //check if console list is empty
        if (consolesBooth.empty())
        {
            cout << "The console booth is empty." << endl << endl;
        }
        else {
            //serve head (front of list)
            console served = consolesBooth.front();
            consolesBooth.pop_front();
            cout << served.name << " ordered console: " << served.console << endl;

            //print remaining list
            cout << endl << "Console Booth:" << endl;
            for (auto& entry : consolesBooth)   // auto used here
            {
                cout << entry.name << endl;
            }
            cout << endl;
        }

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

        //customer joins console booth
        if (rand() % 100 < JOIN)
        {
            //create new node
            console newConsole;
            newConsole.name = names[rand() % 8];
            newConsole.console = consoles[rand() % 5];
            //add to back of list
            consolesBooth.push_back(newConsole);
            //print
            cout << newConsole.name << " joined the console booth." << endl;
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
    head = nullptr;
    currentd = nullptr;

    //delete muffin deque
    muffinOrder* currentm = muffinHead;
    while (currentm != nullptr)
    {
        muffinOrder* temp = currentm;
        currentm = currentm->next;
        delete temp;
    }
    muffinHead = nullptr;
    currentm = nullptr;

    return 0;
}