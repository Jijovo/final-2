//Ezzat Mohamadein | ComSc 210 | Final 2
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <map>
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

//frienfship bracelet vector struct
struct bracelet
{
    string name;
    string fr;
};

//console map struct
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

    //create map of consoles booth, key is position in queue, value is console struct
    map<int, console> consolesBooth;
    for (int i = 0; i < START; i++)
    {
        console newConsole;
        newConsole.name = names[i];
        newConsole.console = consoles[rand() % 5];
        consolesBooth[i] = newConsole;
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

        //customer joins console booth
        if (rand() % 100 < JOIN)
        {
            //create new node
            console newConsole;
            newConsole.name = names[rand() % 8];
            newConsole.console = consoles[rand() % 5];
            //find highest key in map
            int highestKey = 0;
            for (map<int, console>::iterator it = consolesBooth.begin(); it != consolesBooth.end(); it++)
            {
                if (it->first > highestKey)
                {
                    highestKey = it->first;
                }
            }
            //add new node to map
            consolesBooth[highestKey + 1] = newConsole;
            //print
            cout << newConsole.name << " joined the console booth." << endl;
        }

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
        
        //check if console map is empty
        if (consolesBooth.size() == 0)
        {
            cout << "The console booth is empty." << endl << endl;
        }
        else {
            //serve head
            //find lowest key
            int lowestKey = MAX;
            for (map<int, console>::iterator it = consolesBooth.begin(); it != consolesBooth.end(); it++)
            {
                if (it->first < lowestKey)
                {
                    lowestKey = it->first;
                }
            }
            //serve head
            console temp = consolesBooth[lowestKey];
            consolesBooth.erase(lowestKey);
            cout << temp.name << " gets a " << temp.console << endl;

            //print remaining map
            cout << endl << "Console Booth:" << endl;
            for (int i = 0; i < consolesBooth.size(); i++)
            {
                cout << consolesBooth[i].name << endl;
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