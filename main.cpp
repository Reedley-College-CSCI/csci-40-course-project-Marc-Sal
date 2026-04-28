// CSCI-40 Final Project
// Author: Marcos Saldana

/* 
 * Description:
 * Comic Book Tracker: This program  will be keeping track of comics. 
 It will keep track of the issue/volume name, the publishing company, 
 the condition, and the value. It will sort the list from cheapest or 
 to the most expensive or the reverse as well with. The user will be 
 able to remove or add the items. It will be able to search for specific 
 comics either by the name or any of the factors such as a price range.

This program will be useful for collectors that wish to keep track of 
what they collected. Comic book stores can also use this to keep track of 
sales along as helping customers find specific comics or ones in a general 
area such as price range or publishing company.
*/

#include <iostream>
#include <string>

using namespace std;

struct ComicBook {
    //Attributes
    string name;
    string issue; 
    string publisher;
    string condition;
    double value;

};
//Functions
void sortLowestValue (ComicBook array[], int size) { //Sorts the function from lowest value to highest.
    double lowestVal;
    int lowestLocation;
    for (int i = 0; i < (size - 1); i++) {
       lowestVal = array[i].value;
       lowestLocation = i;
       for (int j = i + 1; j < size; j++) {
           if (array[i] < lowestVal) {
               lowestVal = array[j];
               lowestLocation = j;
           }
       }

       swap(array[lowestVal], array[i]);

    }
}
void sortHighestValue (ComicBook array[], int size) { //Sorts the function from highes value to lowest.
    double highestVal;
    int highestLocation;
    for (int i = 0; i < (size - 1); i++) {
        highestVal = array[i].value;
        highestLocation = i;
        for (int j = i + 1; j < size; j++) {
            if (array[i] < highestVal) {
                highestVal = array[j];
                highestLocation = j;
            }
        }

        swap(array[highestVal], highestLocation[i]);

    }
}

int main() {
    
    ComicBook comicList[100];


    return 0;
}
