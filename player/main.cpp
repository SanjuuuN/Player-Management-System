#include "linkedlist.cpp"
#include<iostream>
#include<fstream>
#include "player.h"
using namespace std;




int main() {
    LinkedListPlayer <Pms> lp; // Creating an instance of LinkedListPlayer with double precision
    lp.readFromFile("PlayerData.txt");
    int choice; // Declare choice variable

    do {
        cout << "\n----------------------";
        cout << "\n----------------------";
        cout << "\n     *Menu*       ";
        cout << "\n----------------------";
        cout << "\n----------------------";
        cout << "\n1. Add a new player at a position";
        cout << "\n2. Remove a player from position";
        cout << "\n3. Display all the players";
        cout << "\n4. Update player data";
        cout << "\n5. Display top three players";
        cout << "\n6. Quit\n";
        cout << "----------------------\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "You selected option 1. Add player at position\n";
                int pos;
                int jerNo;
                char name[20];
                int runs;
                int wickets;
                int matches;
                cout << "\nEnter jersey number: ";
                cin >> jerNo;
                fflush(stdin);
                cout << "Enter name: ";
//                cin >> name;
				gets(name);
                cout << "Enter runs: ";
                cin >> runs;
                cout << "Enter wickets: ";
                cin >> wickets;
                cout << "Enter matches: ";
                cin >> matches;
                Pms player(jerNo, name, runs, wickets, matches);
                cout << "\nEnter position: ";
                cin >> pos;
                
                lp.insertPos(player, pos);
                break;
            }
            case 2: {
                cout << "You selected option 2. Remove player from position\n";
                int pos;
                cout << "\nEnter position: ";
                cin >> pos;
                lp.deletePos(pos);
                break;
            }
            case 3: {
                cout << "You selected option 3. Display all the players\n";
                 cout << "+---------------------+----------------------------+--------------------+-------------+---------+\n";
			    cout << "|  Jersey Number     | Name                      |  Runs                |    Wickets  | Matches|\n";
			    cout << "+------------------------------------------------+--------------------+-------------+----------+\n";
                lp.display();
                break;
            }
            case 4: {
                cout << "You selected option 4.\n";
                int jerNo;
                cout << "\nEnter jersey number: ";
                cin >> jerNo;
                lp.updatePlayer(jerNo);
                break;
            }
            case 5: {
                cout << "You selected option 5.\n";
                lp.displayTopThree();
                break;
            }
            case 6: {
                cout << "Exit.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 6); // Loop until choice is 6
	
	lp.writeToFile("PlayerData.txt");
    return 0;
}
