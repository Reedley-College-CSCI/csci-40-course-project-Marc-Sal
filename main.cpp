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
    double value = 0.0;

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
    cout << "Sorted the list from lowest to highest value\n";
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
    cout << "Sorted the list from highest to lowest value\n";
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
    cout << "Sorted the list alphabetically\n";
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
        cout << "Error: List is already filled up\n";
        return 0;
    }
    //Allows for another comic to be entered
    size++;
    //Propmts the user to fulfill what the attributes if the comic
    cin.ignore();
    cout << "What is the name of the comic?\n";
    getline(cin, name);
    cout << "What is the issue of the comic?\n";
    getline(cin, issue);
    cout << "Who is the author of the comic?\n";
    getline(cin, author);
    cout << "Who is the publisher of the comic?\n";
    getline(cin, publisher);
    cout << "What condition is the comic in?\n";
    getline(cin, condition);
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
void  totalValue(ComicBook array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i].value;
    }
    cout << "The value of all the comics: $" << sum << endl;
}

//Exports data into a new file
bool exportFile(ComicBook array[], int size) {
    //Export File
    ofstream outFile("Updated Comics List.txt");
    //Checks if the file can be opened
    if (!outFile) {
        cout << "Unable to open file\n";
        return 0;
    }
    //Loads data into the file
    for (int i = 0; i < size; i++) {
        outFile << array[i].name << endl;
        outFile << array[i].issue << endl;
        outFile << array[i].author << endl;
        outFile << array[i].publisher << endl;
        outFile << array[i].condition << endl;
        outFile << array[i].value << endl;
    }
    cout << "Data has been exported into \"Updated Comics List.txt\"\n";
    outFile.close();
    return 1;
}

int main() {
    //Variables
    int size;
    int maxSize;
    int check;
    double maxPrice = 0.0;
    double minPrice = 0.0;
    char choice;
    char choice2;
    int remove;
    string fileName;
    string authorName;
    string comicName;
    string publisherName;
    ComicBook* comics = nullptr;

    //Set up for main program
    cout << "What is the name of the file being used?\n";
    cin >> fileName;
    cout << "How many comics are in the file\n";
    cin >> size;
    maxSize = size + 10;
    comics = new ComicBook [maxSize];
    while (loadFile(comics, fileName, size) < 0) {
        cout << "Please enter the file name.txt\n";
        cin.ignore();
        cin >> fileName;
    }

    cout << "Would you like to edit the infomarmation? Enter any non negative number to do so.\n";
    cin >> check;

    while (check > -1) {
        cout << "What would you like to do?\n Enter S to sort the data\n Enter F to find certain comics\n ";
        cout << "Enter E to edit the data\n Enter V to find the total value\n Enter P to print the info\n ";
        cout << "Enter X to export the data into a new file\n";
        cin >> choice;
        switch (choice) {
        //Sort Cases
        case 'S':
            cout << "How would you like to sort the info?\n Enter H to sort by highest to lowest value\n ";
            cout << "Enter L to sort by lowest to highest value\n Enter A to sort alphabectically\n ";
            cin >> choice2;
            switch (choice2) {
            case 'H':
                sortHighestValue(comics, size);
                break;
            case 'L':
                sortLowestValue(comics, size);
                break;
            case 'A':
                sortName(comics, size);
                break;
            default:
                cout << "Invalid input. Please make sure the entry is capitalized\n";
                break;
            }
            break;
        //Search Cases
        case 'F':
            cout << "What would you like to seacrh for?\n Enter R to search by a price range\n ";
            cout << "Enter A to search by the author\n Enter N to search by the comic's name\n ";
            cout << "Enter P to search by the publisher\n ";
            cin >> choice2;
            switch (choice2) {
            case 'R':
                cout << "What is the max price point?\n";
                cin >> maxPrice;
                cout << "What is the minimum price point\n";
                cin >> minPrice;
                searchPriceRange(comics, minPrice, maxPrice, size);
                break;
            case 'A':
                cout << "Which author do you want to search for?\n";
                cin.ignore();
                getline(cin, authorName);
                searchAuthor(comics, authorName, size);
                break;
            case 'N':
                cout << "Which comic do you want to search for?\n";
                cin.ignore();
                getline(cin, comicName);
                searchComicName(comics, comicName, size);
                break;
            case 'P':
                cout << "Which publisher do you want to search for?\n";
                cin.ignore();
                getline(cin, publisherName);
                searchPublisher(comics, publisherName, size);
                break;
            default:
                cout << "Invalid input. Please make the entry is Capatalized\n";
                break;
            }
            break;
        case 'E':
            cout << "How would you like to edit the data?\n Enter R to remove a comic\n ";
            cout << "Enter A to add a comic\n";
            cin >> choice2;
            switch (choice2) {
            case 'R':
                printComics(comics, size);
                cout << "Which comic would you like to remove\n";
                cin >> remove;
                removeComic(comics, remove - 1, size);
                break;
            case 'A':
                addComic(comics, maxSize, size);
                break;
            default:
                cout << "Invalid input. Please make the entry is Capatalized\n";
                break;
            }
            break;
        //Info Prining Cases
        case 'P':
            printComics(comics, size);
            break;
        case 'X':
            exportFile(comics, size);
            break;
        default:
            cout << "Invalid input. Please make the entry is Capatalized\n";
            break;
        }
        cout << "Would you like to countinue editing the infomarmation? Enter any non negative number to do so.\n";
        cin >> check;
    }
    //Make sure the user wants to keep the data instead of losing it
    cout << "Do you want to export the data into another file before exiting the program? Enter Y for yes or any other letter for no.\n";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        exportFile(comics, size);
    }
    cout << "Thank you for using this program\n";
    delete[] comics;
    return 0;
}
