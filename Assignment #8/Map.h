//********************************************************************
// ASU CSE310 Assignment #8 Fall 2024
// Name of Author: PO-YI, LIN
// ASU ID: 1228434521
// Description: This is the header file that defines an undirected graph
//              with an array of sites and routes
//********************************************************************

//include necessary header file here
//----
#include "Route.h"
#include <algorithm>

using namespace std;

class Map
{
private:
    int numOfSites, numOfRoutes;
    Site* setOfSites;   //an array of Site. Note: NOT allowed to change it to Site**
    Route* setOfRoutes; //an array of Route. Note: NOT allowed to change it to Route**

public:
    Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray);
    ~Map();
    void make_set(Site* oneSite);
    Site* find_set(Site* oneSite);
    void link(Site* aSite, Site* bSite);
    void Union(Site* aSite, Site* bSite);
    void sortRoutes();
    void MST_Kruskal();
    void QuickSortLauncher(Route* routeArray);
    void QuickSort(Route* routeArray, int p, int r);
    int partition(Route* routeArray, int p, int r);

    //add any auxiliary functions in case you need them
    //----
};


//finish each function according to above definition
//----
//----
//Contructor. Used to initialize all instance variables
Map::Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray) {
    this->numOfSites = numOfSites;
    this->numOfRoutes = numOfRoutes;
    this->setOfSites = siteArray;
    this->setOfRoutes = routeArray;
}

//Destructor. Use to release all dynamic allocated memory.
Map::~Map() {
    delete[] setOfSites;
    delete[] setOfRoutes;
}

//Given a Site object, this function creates a new set whose only member is the Site itself.
void Map::make_set(Site* oneSite) {
    oneSite->parent = oneSite;
    oneSite->rank = 0;
}

//Given a Site object, this function returns a pointer that points to the representative of the(unique) set containing 'aSite'
Site* Map::find_set(Site* oneSite) {
    if (oneSite->siteName != oneSite->parent->siteName) {
        oneSite->parent = find_set(oneSite->parent);
    }
    return oneSite->parent;
}

//Given two Site objects, this function checks the dynamic sets that contain the parameterized 'aSite' and 'bSite' and update their rank and parent info.accordingly
void Map::link(Site* aSite, Site* bSite) {
    if (aSite->rank > bSite->rank) {
        bSite->parent = aSite;
    }
    else if (aSite->rank < bSite->rank) {
        aSite->parent = bSite;
    }
    else {
        aSite->parent = bSite;
        bSite->rank++;
    }
}

//Given two Site objects, this function unites the dynamic sets that contain the parameterized 'aSite' and 'bSite' into a new set that is the union of the two sets.
void Map::Union(Site* aSite, Site* bSite) {
    link(find_set(aSite), find_set(bSite));
}

//This function sorts all Routes according to their length in non-decreasing order. Note: use the best sorting algorithms, such as MergeSort, QuickSort or HeapSort. You are NOT allowed to use insertion sort, selection sort, or Bubble sort, etc.
void Map::sortRoutes() {
    QuickSortLauncher(setOfRoutes);
}


//QuickSortLauncher
void Map::QuickSortLauncher(Route* routeArray) {
    int p = 0;
    int r = numOfRoutes - 1;
    QuickSort(routeArray, p, r);
}

//QuickSort
void Map::QuickSort(Route* routeArray, int p, int r) {
    if (p < r) {
        int q = partition(routeArray, p, r);
        QuickSort(routeArray, p, q-1);
        QuickSort(routeArray, q+1, r);
    }
}

//Partition function
int Map::partition(Route* routeArray, int p, int r) {
    double x = routeArray[r].getDistance();
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (routeArray[j].getDistance() <= x) {
            i++;
            swap(routeArray[i], routeArray[j]);
        }
    }
    swap(routeArray[i+1], routeArray[r]);
    return i + 1;
}

//*******************************************************************
//This function performs the Kruskal algorithm on the graph
void Map::MST_Kruskal()
{
    cout << "\nMST Kruskal Algorithm Result\n" << endl;
    double totalDistance = 0.0;

    //----
    //----
    //----
    for (int i = 0; i < numOfSites; i++) {
        make_set(&setOfSites[i]);
    }
    sortRoutes();
    for (int i = 0; i < numOfRoutes; i++) {
        if (find_set(setOfRoutes[i].getSite1()) != find_set(setOfRoutes[i].getSite2())) {
            setOfRoutes[i].printRoute();
            totalDistance = totalDistance + setOfRoutes[i].getDistance();
            Union(setOfRoutes[i].getSite1(), setOfRoutes[i].getSite2());
        }
    }

    cout << "=====================================================================================" << endl;
    cout << "Total Distance: " << totalDistance << " meters" << endl;
}
