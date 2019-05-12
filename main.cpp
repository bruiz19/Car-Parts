#include <iostream> // Read/Write to console
#include <fstream>  // Read/Write to files
#include <string>   // String class to more easily handle this data type
#include <vector>   // Storage class, used to store "Part" objects

#include "Part.cpp"

using namespace std;
// forward declarations, not strictly necessary, but sometimes helpful
char getCommand();
Part newPart();
void findPart(vector<Part> & myList);
void archiveData(string myFile, vector<Part> & myList);
void readDataFromFile(string myFile, vector<Part> & myList);


int main() {
    const string FILENAME = "input.txt";
    const string OUTPUTFILE = "output.txt";

    char cmd;
    vector<Part> myPartsList; // create empty vector to store parts

    readDataFromFile(FILENAME, myPartsList); // read the storage file

     do {
        cmd = getCommand();
        switch (cmd) {
            case 'n' : myPartsList.push_back(newPart());
            break;

            case 'f' : findPart(myPartsList);
            break;

            case 'q' : ; // no extra code and no break, we want q to do the 'a' action as well

            case 'a' : archiveData(OUTPUTFILE, myPartsList);
            break;

            default : break;
        }
    } while (cmd != 'q');
    return 0;
}

char getCommand() {
    char cmd = 'a';
    cout << endl << "Please enter one of the following commands:\n(N)ew Part\n(F)ind a Part\n(A)rchive data\n(Q)uit\n->";
    cin >> cmd;
    return tolower(cmd); // in case they enter capital letters
}

Part newPart() {
    int id;
    string desc = "";
    cout << "Enter the part number: ";
    cin >> id;
    getline(cin, desc); // this clears the buffer in prep for the next getline()
    cout << "Type the part description: ";
    getline(cin, desc);
    return Part(id, desc);
}

void findPart(vector<Part> & myList) {
    int num = 0;
    cout << "Which part number do you want to search for (enter part ID)?: ";
    cin >> num;
    cout << endl;
    for (unsigned i=0; i < myList.size(); i++) {
        if (myList.at(i).getID() == num) {
            cout << "Part number: " << myList.at(i).getID() << "\nDescription: " << myList.at(i).getDescription() << endl << endl;
            return;
        }
    }
    cout << "This part was not found." << endl << endl;
}

void archiveData(string myFile, vector<Part>  & myList) {
    ofstream file;
    file.open(myFile);
    // Writing to the file is trivial and can be accomplished just like writing to the screen
    for (unsigned i = 0; i < myList.size(); i++) {
        file << myList.at(i).getID() << endl << myList.at(i).getDescription() << endl;
    }
    file.close();
}

void readDataFromFile(string myFile, vector<Part> & myList){
    int id;
    string desc = "";
    ifstream file;
    file.open(myFile);
    while(file >> id) {
            getline(file, desc); // clear the buffer in prep for the next getline()
            getline(file, desc); // get the next line
            myList.push_back(Part(id, desc)); // create and store each part
        }
    file.close();
}
