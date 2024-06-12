#include<iostream>

#include<iomanip>
#include<fstream>
using namespace std;



#ifndef PLAYER_H  //prevents duplication and ensures that all necessary declarations and definitions are available to the compiler without causing conflicts.
#define PLAYER_H
class Pms {
    int jerNo;
    char name[20];
    int runs;
    int wickets;
    int matches;

	public:
    Pms();
    Pms(int, const char*, int, int, int);

    int getJerseyNumber();
    const char* getName();
    int getRuns();
    int getWickets();
    int getMatches();

    void setJerseyNumber(int);
    void setName(const char*);
    void setRuns(int);
    void setWickets(int);
    void setMatches(int);
    void display();
};
#endif

