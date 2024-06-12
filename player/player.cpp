#include "player.h"

#include <iostream>
#include <iomanip> // Include for setw
using namespace std;
////////////////////////////////////////////////////////
//default constructor
Pms::Pms() {
    jerNo = 0;
    strcpy(name, "notgiven");
    runs = 0;
    wickets = 0;
    matches = 0;
}

////////////////////////////////////////////////////////
//parameterized constructor
Pms::Pms(int jerNo, const char* name, int runs, int wickets, int matches) {
    this->jerNo = jerNo;
    strcpy(this->name, name);
    this->runs = runs;
    this->wickets = wickets;
    this->matches = matches;
}

////////////////////////////////////////////////////////

// Getter and setter methods
int Pms::getJerseyNumber() {
    return jerNo;
}

////////////////////////////////////////////////////////

const char* Pms::getName() {
    return name;
}
////////////////////////////////////////////////////////

int Pms::getRuns() {
    return runs;
}
////////////////////////////////////////////////////////

int  Pms::getWickets() {
    return wickets;
}
////////////////////////////////////////////////////////

int Pms::getMatches() {
    return matches;
}
////////////////////////////////////////////////////////

void Pms::setJerseyNumber(int jersey) {
    jerNo = jersey;
}
////////////////////////////////////////////////////////

void Pms::setName(const char* playerName) {
    strcpy(name, playerName);
}
////////////////////////////////////////////////////////

void Pms::setRuns(int playerRuns) {
    runs = playerRuns;
}
////////////////////////////////////////////////////////

void Pms::setWickets(int playerWickets) {
    wickets = playerWickets;
}
////////////////////////////////////////////////////////

void  Pms::setMatches(int playerMatches) {
    matches = playerMatches;
}
////////////////////////////////////////////////////////

void Pms::display() {
//    cout << "+---------------------+----------------------------+--------------------+-------------+---------+\n";
//    cout << "|  Jersey Number     | Name                      |  Runs                |    Wickets  | Matches|\n";
//    cout << "+------------------------------------------------+--------------------+-------------+----------+\n";
    printf("| %-18d | %-25s | %-21d | %10d | %-6d |\n",
           jerNo, name, runs, wickets, matches);
    cout << "------------------------------------------------------------------------------------------------+\n";
    cout << "\n";
}
////////////////////////////////////////////////////////