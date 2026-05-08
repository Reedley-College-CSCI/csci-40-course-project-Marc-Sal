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
#include <fstram>

using namespace std;

struct ComicBook {
    //Attributes
    string name;
    string issue;
    string author;
    string publisher;
    string condition;
    double value;

};
//Functions
int loadFile(ComicBook array[], string fileName,  int size) {
    ifstream file(fileName);

    if (!file) {
        cout << "Unable to open file\n";
        return 0;
    }
    int count = 0;
    while (count < size && file >> array[count].name
        >> array[count].issue >> array[count].author
        >> array[count].publisher >> array[count].condition
        >> array[count].value) {
        count++;
    }
    file.closs();
    return count;
}
// Sort Functions
//Sorts the array  from lowest value to highest.
void sortLowestValue(ComicBook array[], int size) {
    double lowestVal;
    int lowestLocation;
    for (int i = 0; i < (size - 1); i++) {
        lowestVal = array[i].value;
        lowestLocation = i;
        for (int j = i + 1; j < size; j++) {
            if (array[i].value < lowestVal) {
                lowestVal = array[j].value;
                lowestLocation = j;
            }
        }

        swap(array[lowestVal], array[i]);

    }
}

//Sorts the array from highes value to lowest.
void sortHighestValue(ComicBook array[], int size) {
    double highestVal;
    int highestLocation;
    for (int i = 0; i < (size - 1); i++) {
        highestVal = array[i].value;
        highestLocation = i;
        for (int j = i + 1; j < size; j++) {
            if (array[i].value < highestVal) {
                highestVal = array[j].value;
                highestLocation = j;
            }
        }

        swap(array[highestVal], array[i]);

    }
}

//Sorts the array based on the Comic name ***FINISH THIS ONE****
void sortName(ComicBook array[], int size) {
    string highestName;
    int highestLocation;
    for (int i = 0; i < (size - 1); i++) {
        highestName = array[i].name;
        highestLocation = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j].name < highestName) {
                highestName = array[j].name;
                highestLocation = j;
            }
        }
        swap(array[highestLocation], array[i]);

    }
}

//Sort Functions
//Searches for comics in a price range
void searchPriceRange(ComicBook array[], double min, double max, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i].value <= max && array[i].value >= min) {
            cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                <<" Publisher: " << array[i].publisher << "  Condition: " << array[i].condition 
                << " Value: " << array[i].value << endl;
        }
    }
}

//Searches based on publisher
void searchAuthor (ComicBook array[], string author, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i].author == author) {
            cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition
                << " Value: " << array[i].value << endl;
        }
    }
}

//Searches for specific comics
void searchComicName(ComicBook array[], string comicName, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i].name == comicName) {
            cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition
                << " Value: " << array[i].value << endl;
        }
    }
}

//Searches for specific publisher
void searchPublisher(ComicBook array[], string publisher, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i].publisher == publisher) {
            cout <<  i + 1 << " Name: "  << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition
                << " Value: " << array[i].value << endl;
        }
    }
}

//Array Editors
//Removes an item from the array
void removeComic(ComicBook array[], string comicName, int size) {
    int comicDestroyer;
    searchComicName(array[], comicName, size);
    cout << "Which comic one would you like to remove?\n ";
    cin >> comicDestroyer;
    comicDestroyer = comicDestroyer - 1;
    delete(array[comicDestroyer]);
}

//Info Printing
//Prints out the list of Comics
void printComics (ComicBook array[], int size) {
    for (int i = 0; i < (size - 1); i++) {
        cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
            << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition 
            << " Value: " << array[i].value << endl;
    }
}

//Print the Value of all comics
double  totalValue(ComicBook array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size - 1; i++) {
        sum += array[i].value;
    }
    cout << "The value of all the comics: $" << sum << endl;
}

const int MAX_SIZE = 10;
int main() {
    
    ComicBook comicList[MAX_SIZE];


    return 0;
}
