#include "todo.h"
#include <vector>

using namespace std;


void addToDo();
void popToDo();
void displayList();

vector<todo> toDoList; /* FIFO queue of TODOs */

/* End goal: to-do lists are saved and persistent through states of the program.  */
int main(void) {

    int keepgoing = 1;





    while (keepgoing) {
        int option;

        displayList();
        cout << "What would you like to do?" << endl;
        cout << "(1) Add a to-do to the list" << endl;
        cout << "(2) Remove a to-do from the list" << endl;
        cout << "(3) Exit " << endl;

        cout << "Choice: ";
        cin >> option;

        switch(option) {
            case 1:
                addToDo();
            break;
            case 2:
                popToDo();
            break;
            case 3:
                cout << "See you later!" << endl;
                keepgoing = 0;
            break;
            default:
                cout << "This choice does not exist yet" << endl;
        }
    }
}

void displayList() {
    cout << "****** TO-DO LIST ******" << endl;
    for (int i = 0; i < toDoList.size(); i++) {
        cout << "* (" << i << ")" << toDoList.at(i) << endl;
    }
    cout << "****** END LIST ********" << endl;
}

void addToDo() {
    string content;

    cout << "What would you like to put on the list?" << endl;
    cin >> content;

    todo newToDo = {toDoList.size(), content};

    toDoList.push_back(newToDo);

    cout << "New reminder added to the list!" << endl;
}

void popToDo() {
    cout << "Removing earliest to-do from the list..." << endl;
    toDoList.pop_back();

    cout << "Earliest to-do removed!" << endl;
}
