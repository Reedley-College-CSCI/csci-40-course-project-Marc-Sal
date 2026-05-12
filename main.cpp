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
#include <fstream>

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
    while (count < size && getline(file, array[count].name)
        && getline(file, array[count].issue) && 
        getline(file, array[count].author) &&
        getline(file, array[count].publisher) &&
        getline(file, array[count].condition) &&
        (file >> array[count].value)) {
        file.ignore();
        count++;
    }
    file.close();
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
            if (array[j].value < lowestVal) {
                lowestVal = array[j].value;
                lowestLocation = j;
            }
        }

        swap(array[lowestLocation], array[i]);

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
            if (array[j].value > highestVal) {
                highestVal = array[j].value;
                highestLocation = j;
            }
        }

        swap(array[highestLocation], array[i]);

    }
}

//Sorts the array based on the Comic name ***FINISH THIS ONE****
void sortName(ComicBook array[], int size) {
    string highestName;
    int highestLocation;
    for (int i = 0; i < (size); i++) {
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
    for (int i = 0; i < size; i++) {
        if (array[i].value <= max && array[i].value >= min) {
            cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                <<" Publisher: " << array[i].publisher << "  Condition: " << array[i].condition 
                << " Value: " << array[i].value << endl;
        }
    }
}

//Searches based on publisher
void searchAuthor (ComicBook array[], string author, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].author == author) {
            cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition
                << " Value: " << array[i].value << endl;
        }
    }
}

//Searches for specific comics
void searchComicName(ComicBook array[], string comicName, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].name == comicName) {
            cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition
                << " Value: " << array[i].value << endl;
        }
    }
}

//Searches for specific publisher
void searchPublisher(ComicBook array[], string publisher, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i].publisher == publisher) {
            cout <<  i + 1 << " Name: "  << array[i].name << " " << array[i].issue << " Author: " << array[i].author
                << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition
                << " Value: " << array[i].value << endl;
        }
    }
}

//Array Editors
//Removes an item from the array **REVIEW THIS ONE****
bool removeComic(ComicBook array[], int location, int& size) {
    if (location < 0 || location >= size) {
        cout << "Error: Location in not available\n";
        return 0;
    }
        swap(array[location], array[size - 1]);
        size--;
        cout << "Removed the comic\n";
        return 1;
}

//Adds a comic if the array isn't already filled up
bool addComic(ComicBook array[], int maxSize, int& size) {
    //Variables for new entry
    string name;
    string issue;
    string author;
    string publisher;
    string condition;
    double value;

    //Checks to see if the array is already filled up
    if (maxSize == size) {
        cout "Error: List is already filled up\n";
        return 0;
    }
    //Allows for another comic to be entered
    size++;
    //Propmts the user to fulfill what the attributes if the comic
    cout << "What is the name of the comic?\n";
    cin >> name;
    cout << "What is the issue of the comic?\n";
    cin >> issue;
    cout << "Who is the author of the comic?\n";
    cin >> author;
    cout << "Who is the publisher of the comic?\n";
    cin >> publisher;
    cout << "What condition is the comic in?\n";
    cin >> condition;
    cout << "What is the value of the comic?\n";
    cin >> value;

    //Inputs the attributes into the array
    array[size - 1].name = name;
    array[size - 1].issue = issue;
    array[size - 1].author = author;
    array[size - 1].publisher = publisher;
    array[size - 1].condition = condition;
    array[size - 1].value = value;
    return 1;
}
//Info Printing
//Prints out the list of Comics
void printComics (ComicBook array[], int size) {
    for (int i = 0; i < (size); i++) {
        cout << i + 1 << " Name: " << array[i].name << " " << array[i].issue << " Author: " << array[i].author
            << " Publisher: " << array[i].publisher << "  Condition: " << array[i].condition 
            << " Value: " << array[i].value << endl;
    }
}

//Print the Value of all comics
double  totalValue(ComicBook array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i].value;
    }
    cout << "The value of all the comics: $" << sum << endl;
}


int main() {
    int size;
    int maxSize;
    cin >> size;
    maxSize = size;
    ComicBook* comics = nullptr;
    comics = new ComicBook [size];
    loadFile(comics, "comicBooks.txt", MAX_SIZE);

    //cout << "Total Value: " << totalValue(comicList, MAX_SIZE) << endl;
    //searchPublisher(comicList, "DC", MAX_SIZE);
    //searchComicName(comicList, "Spawn", MAX_SIZE);
    //sortHighestValue(comicList, MAX_SIZE);
    //searchPriceRange(comicList, 100, 200, MAX_SIZE);

    removeComic(comics, 3 - 1, size);
    addComic(comics, maxSize, size);
    printComics(comicList, size);

    return 0;
}
