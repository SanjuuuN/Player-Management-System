#include "node.cpp"
#include<string.h>


template<class T>
class LinkedListPlayer {
    Node<T>* start;

public:
    LinkedListPlayer();
    void display();
    bool insertPos(T&, int);
    bool insertEnd(T&);
    void deletePos(int);
    void updatePlayer(int);
    void displayTopThree();
    ~LinkedListPlayer();
    void writeToFile(const char*);
    void readFromFile(const char*);    
};