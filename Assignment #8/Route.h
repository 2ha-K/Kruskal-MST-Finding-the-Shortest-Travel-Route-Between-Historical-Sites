//********************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name of Author: PO-YI, LIN
// ASU ID: 1228434521
// Description: //---- is where you should add your own code
//********************************************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Site represents one vertex of the map
struct Site
{
    string siteName;
    int rank;
    struct Site* parent;

    //C++ doesn't provide a default constructor, need it here.
    Site()
    {
        //----
        //----
        this->siteName = "Not set yet";
        this->rank = 0;
        this->parent = nullptr;
    }

    //overloaded constructor
    Site(string name)
    {
        //----
        //----
        this->siteName = name;
        this->rank = 0;
        this->parent = nullptr;
    }
};

//Route represents one edge of the map which connects two historical sites of Rome
class Route
{
private:
    struct Site* site1;
    struct Site* site2;
    double distance;

public:
    Route();
    Route(Site* site1, Site* site2, double distance);
    Site* getSite1();
    Site* getSite2();
    double getDistance();
    void printRoute();
};

//finish each function according to above definition
//----
//----
//Constructure of defalut
Route::Route() {
    this->site1 = nullptr;
    this->site2 = nullptr;
    this->distance = 0;
}

//This is the overloaded constructor.
Route::Route(Site* site1, Site* site2, double distance) {
    this->site1 = site1;
    this->site2 = site2;
    this->distance = distance;
}

//Accessor for instance variable site1
Site* Route::getSite1() {
    return site1;
}

//Accessor for instance variable site2
Site* Route::getSite2() {
    return site2;
}

//Accessor for instance variable distance
double Route::getDistance() {
    return distance;
}

//This function prints the Route info. on screen
void Route::printRoute()
{
    cout << left;
    cout << setw(33) << site1->siteName
        << setw(8) << "<--->"
        << setw(33) << site2->siteName
        << setw(3) << " = "
        << setw(8) << right << fixed << setprecision(1) << getDistance()
        << endl;
}
