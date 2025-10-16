#include "todo.h"
#include <vector>
#include <limits>
#include <cstdlib>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;


void addToDo();
void popToDo();
void displayList();
void clearScreen();
void pressAnyKey();
bool fileExists(const string& filename);
void loadList();
void saveList();
void popById();

vector<todo> toDoList; /* LIFO queue of TODOs */

/* End goal: to-do lists are saved and persistent through states of the program.  */
int main(void) {

    int keepgoing = 1;

    if (fileExists("todo.txt")) {
        loadList();
    }

    while (keepgoing) {
        int option;

        clearScreen();
        displayList();
        cout << "What would you like to do?" << endl;
        cout << "(1) Add a to-do to the list" << endl;
        cout << "(2) Remove a to-do from the list" << endl;
        cout << "(3) Exit " << endl;

        cout << "Choice: ";
        if (!(cin >> option)) {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid input! Please enter a number.\n";
               pressAnyKey();
               continue;
        }

        switch(option) {
            case 1:
                addToDo();
            break;
            case 2:
                cout << "Remove... " << endl;
                cout << "(1) Last item\n(2) By ID" << endl;
                cout << "Choice? "; 
                int choice; 
                cin >> choice; 
                if (choice == 1) {
                    popToDo();
                }
                else if (choice == 2) {
                    popById(); 
                }
            break;
            case 3:
                cout << "See you later!" << endl;
                keepgoing = 0;
            break;
            default:
                cout << "This choice does not exist yet" << endl;
        }
    }
    saveList();
}


void displayList() {
    cout << "****** TO-DO LIST ******" << endl;
    for (int i = 0; i < (int)toDoList.size(); i++) {
        cout << "* (" << i << ")" << toDoList[i].getContent() << endl;
    }
    cout << "****** END LIST ********" << endl;
}

void addToDo() {
    string content;

    cout << "What would you like to put on the list?" << endl;
    cin.ignore();
    getline(cin, content);

    todo newToDo = {static_cast<int>(toDoList.size()), content};
    toDoList.push_back(newToDo);

    cout << "New reminder added to the list!" << endl;
    pressAnyKey();
}

void popToDo() {
    cout << "Removing earliest to-do from the list..." << endl;
    if (toDoList.size() > 0) {
        toDoList.pop_back();
        cout << "Earliest to-do removed!" << endl;
    }
    else {
        cout << "Error: cannot remove from empty list" << endl;
    }
    pressAnyKey();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // for windows
    #else
        system("clear"); // for normal people
    #endif
}

void pressAnyKey() {
    cout << "\nPress any key to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover input
    cin.get(); // wait for Enter
}

bool fileExists(const string& filename) {
    /* True if exists, false otherwise */
    return fs::exists(filename);
}

void loadList() {
    ifstream inFile("todo.txt");
    string line;
    while (getline(inFile, line)) {
        todo newToDo = {static_cast<int>(toDoList.size()), line};
        toDoList.push_back(newToDo);
    }
}

void saveList() {
    ofstream outFile("todo.txt");
    for (auto& item : toDoList) {
        outFile << item.getContent() << endl;
    }
}

void popById() {
    if (toDoList.empty()) {
        cout << "The list is empty!" << endl;
        pressAnyKey();
        return;
    }

    int id;
    cout << "Enter the ID of the to-do you want to remove: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        pressAnyKey();
        return;
    }

    bool found = false;
    for (auto it = toDoList.begin(); it != toDoList.end(); it++) {
        if (it->getID() == id) {
            toDoList.erase(it);
            found = true;
        }
    }

    /* Reassign IDs so they match their indices */
    if (found) {
        for (int i = 0; i < (int)toDoList.size(); i++) {
            toDoList[i].setID(i);
        }
        cout << "To-do removed successfully!" << endl;
    }
    else {
        cout << "No to-do found with ID " << id << endl;
    }

    pressAnyKey();
}
