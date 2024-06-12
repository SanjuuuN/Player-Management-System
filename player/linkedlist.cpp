#include "linkedlist.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////
template<class T>
LinkedListPlayer<T>::LinkedListPlayer() {
    start = nullptr;
}
////////////////////////////////////////////////////////
template<class T>
void LinkedListPlayer<T>::display() {
    if (start == nullptr) {
        cout << "No nodes to display." << endl;
        return;
    }
   
    Node<T>* p = start;
    while (p != nullptr) {
    
        p->getData().display();
        p = p->getNext();
    }
}
////////////////////////////////////////////////////////
template<class T>
bool LinkedListPlayer<T>::insertPos(T& data, int pos) {
    Node<T>* temp = new Node<T>(data);
    if (start == nullptr || pos == 1) {
        temp->setNext(start);
        start = temp;
        return true;
    }
    int i = 1;
    Node<T>* p = start;
    while (i < pos - 1 && p->getNext() != nullptr) {
        p = p->getNext();
        i++;
    }
    temp->setNext(p->getNext());
    p->setNext(temp);
    return true;
}

////////////////////////////////////////////////////////
template<class T>
bool LinkedListPlayer<T>::insertEnd(T& data) {
    Node<T>* temp = new Node<T>(data);
    if (start == nullptr) {
        start = temp;
    } else {
        Node<T>* p = start;
        while (p->getNext() != nullptr) {
            p = p->getNext();
        }
        p->setNext(temp);
    }
    return true;
}
////////////////////////////////////////////////////////
template<class T>
void  LinkedListPlayer<T>::deletePos(int pos) {
    if (start == nullptr) {
        cout << "No nodes to delete." << endl;
        return;
    }
    Node<T>* p = start;
    if (pos == 1) {
        start = start->getNext();
        delete p;
        cout << "Node deleted." << endl;
        return;
    }
    int i = 1;
    while (i < pos - 1 && p->getNext() != nullptr) {
        p = p->getNext();
        i++;
    }
    if (i == pos - 1 && p->getNext() != nullptr) {
        Node<T>* q = p->getNext();
        p->setNext(q->getNext());
        delete q;
        cout << "Node deleted." << endl;
        return;
    } else {
        cout << "Invalid position." << endl;
    }
}
////////////////////////////////////////////////////////

template<class T>
void LinkedListPlayer<T>::updatePlayer(int jerNo) {
    if (start == nullptr) {
        cout << "No nodes to update." << endl;
        return;
    }

    Node<T>* p = start;
    bool found = false;

    while (p != nullptr) {
        if (jerNo == p->getData().getJerseyNumber()) {
            T& P = p->getData();
            cout << "Found." << endl;

            char playerName[20];
            cout << "Enter new name: ";
            cin.ignore();    // Ignore any remaining newline characters in the buffer
            cin.getline(playerName, sizeof(playerName));

            int choice;
            cout << "Enter your choice to update 1. Runs 2. Wickets 3. Matches: ";
            cin >> choice;

            double newValue;
            if (choice == 1) {
                cout << "Enter new runs: ";
                cin >> newValue;
                P.setRuns(newValue);
            } else if (choice == 2) {
                cout << "Enter new wickets: ";
                cin >> newValue;
                P.setWickets(newValue);
            } else if (choice == 3) {
                cout << "Enter new matches: ";
                cin >> newValue;
                P.setMatches(newValue);
            } else {
                cout << "Invalid choice." << endl;
                break;
            }

            P.setName(playerName);
            found = true;
            cout << "Player updated successfully." << endl;
            break;
        }
        p = p->getNext();
    }

    if (!found) {
        cout << "Player not found." << endl;
    }
}


////////////////////////////////////////////////////////
template<class T>
void LinkedListPlayer<T>::displayTopThree() {
    T sortedArray[100];  // Adjust the size as needed
    int count = 0;
	 if (start == nullptr) {
        cout << "No nodes to Display." << endl;
        return;
    }
    Node<T>* current = start;
    while (current && count < 100) {
        sortedArray[count++] = current->getData();
        current = current->getNext();
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (sortedArray[j].getRuns() < sortedArray[j + 1].getRuns()) {
                T temp = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = temp;
            }
        }
    }

    cout << "+---------------------+----------------------------+--------------------+-------------+---------+\n";
    cout << "|  Jersey Number     | Name                      |  Runs                |    Wickets  | Matches|\n";
    cout << "+------------------------------------------------+--------------------+-------------+----------+\n";
    for (int i = 0; i < min(3, count); ++i) {
        cout << "| " << setw(18) << sortedArray[i].getJerseyNumber() << " | "
             << setw(25) << sortedArray[i].getName() << " | "
             << setw(21) << sortedArray[i].getRuns() << " | "
             << setw(10) << sortedArray[i].getWickets() << " | "
             << setw(6) << sortedArray[i].getMatches() << " |\n";
    }
    cout << "------------------------------------------------------------------------------------------------+\n";
}
////////////////////////////////////////////////////////
template<class T>
LinkedListPlayer<T>::~LinkedListPlayer() {
    Node<T>* p = start;
    while (p != nullptr) {
        Node<T>* temp = p;
        p = p->getNext();
        delete temp;
    }
}
////////////////////////////////////////////////////////
template<class T>
void LinkedListPlayer<T>::writeToFile(const char* fileName)
{
    ofstream outFile(fileName, ios::binary);//file opens in binary mode
    if (!outFile)  //if file fails to open 
    {
        cout << "\nDisclaimer -> File not opened...";
        return;
    }
    Node<T>* p = start;
    while (p != NULL)
    {
        outFile.write((char*)(&p->getData()), sizeof(T)); //  (char*) ->converts the address of the data to a char* type pointer, write function expects a pointer to characters (char*) as its first argument.
        p = p->getNext();
    }
    outFile.close();
}
////////////////////////////////////////////////////////
template<class T>
void LinkedListPlayer<T>::readFromFile(const char* fileName)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile) //if file fails to open 
    {
        cout << "\nDisclaimer -> File not opened...";
        return;
    }
    T p;
    while (inFile.read((char*)(&p), sizeof(T))) 
    {
        insertEnd(p);
    }
    inFile.close();
}
////////////////////////////////////////////////////////