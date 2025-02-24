//************************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// ASU ID: 1228434521
// Name: PO-YI, LIN
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph. //---- is where you need to add your own codes
//**************************************************************************

//include necessary header file
//----
#include "Map.h";
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance);

int main()
{
    //Maximum possible sites and route number
    const int MAX_SITE_NUM = 50, MAX_ROUTE_NUM = 100;
    int numOfSites = 0, numOfRoutes = 0;  //counter used to track actual number of sites and routes


    //create an array of Site which store all Sites (vertex of the graph)
    //----
    Site* arrayOfSites = new Site[MAX_SITE_NUM];

    //create an array of Route which store all Routes (edges of the graph)
    //----
    Route* arrayOfRoutes = new Route[MAX_ROUTE_NUM];

    //declare all necessary local variables here
    //
    string firstToken;
    string token;
    Route* aNewRoute;
    Site* site1;
    Site* site2;
    string oneLine;
    double distance;
    bool insert = true;

    getline(cin, oneLine);

    while (oneLine.compare("End") != 0)
    {
        //get one line from the input, extract the first token
        istringstream iss(oneLine);
         getline(iss, firstToken, ',');
        //create a Site object if it does not exist in site array tham
        site1 = new Site(firstToken);
        for (int i = 0; i < numOfSites; i++) {//checking is the site in the site array.
            if (site1->siteName == arrayOfSites[i].siteName) {
                cout << "The Site is already in the array" << endl;
                delete(site1);
                insert = false;
                site1 = &arrayOfSites[i];
                break;
            }
        }
        if (insert) {//if not inside put it behind the last one controll by number of numofsize.
            arrayOfSites[numOfSites] = *site1;
            numOfSites++;
        }
        insert = true;

        

        //insert it inside the site array. This will be first point of the 'aNewRoute'
        //----
        //----
        while (getline(iss, token, ',')) {
            if (token.empty()) {//find is the next taken is empty or not
                continue;
            }
            site2 = new Site();
            getArrSiteInfo(token, site2->siteName, distance);//use get inform to get our name and distance from string
            for (int i = 0; i < numOfSites; i++) {
                if (site2->siteName == arrayOfSites[i].siteName) {
                    cout << "The Site is already in the array" << endl;
                    delete(site2);
                    insert = false;
                    site2 = &arrayOfSites[i];
                    break;
                }
            }
            if (insert) {
                arrayOfSites[numOfSites] = *site2;
                numOfSites++;
            }
            aNewRoute = new Route(site1, site2, distance);//Due to those are private, i collect this 3 at first and put them in the same time.
            arrayOfRoutes[numOfRoutes] = *aNewRoute;
            numOfRoutes++;
        }
        insert = true;
        iss.clear();

        //extract the arrival site info. check whether it exists in
        //site array or not, if not, create a new Site object, add it inside.
        //This site will be the second point of the 'aNewRoute'
        //----
        //----

        //by using the two sites we got above, create a new route, add
        //it inside route array
        //----
        //----

        //get next line
        getline(cin, oneLine);

    } //repeat until the 'End'

    //Create a Map object by using site array and route array
    //----
    Map* map = new Map(numOfSites, numOfRoutes, arrayOfSites, arrayOfRoutes);
    
    //code for testing is the array truly collected those data
    //cout << "Test of vertex"<<endl;
    //for (int i = 0; i < numOfSites;i++) {
    //    cout << "Vertex " <<i<<" is:" << arrayOfSites[i].siteName<< endl;
    //}
    //cout << "Test of routes" << endl;
    //for (int i = 0; i < numOfSites; i++) {
    //    cout << "route " << i << " is:" << endl;
    //    arrayOfRoutes[i].printRoute();
    //    cout << endl;
    //}

    cout << "Total historical sites you will visit: " << numOfSites << endl;

    //Run Kruskal MST algorithm on above map
    //----
    map->MST_Kruskal();
}

//****************************************************************
//By giving a string, for example 'Pantheon(300.5)', this function
//extract the arrival site name 'Pantheon' and distance '300.5' meters
//Note: the delimiter is left and right parenthesis
//****************************************************************
//Seperate oneArrSiteInfo to arrSiteName and distance using size_t to find position of "(" and ")".
void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance)
{
    //----
    //----
    size_t pos1 = oneArrSiteInfo.find('(');
    size_t pos2 = oneArrSiteInfo.find(')');
    arrSiteName = oneArrSiteInfo.substr(0, pos1);
    distance = stod(oneArrSiteInfo.substr(pos1+1, pos2-pos1-1));
}
