#include "todo.h"
#include <vector>

using namespace std;


void addToDo(); 
void popToDo(); 
/* End goal: to-do lists are saved and persistent through states of the program.  */
int main(void) {

    int keepgoing = 1;

    while (keepgoing) {
        int option; 
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
                exit(0); 
            break;
            default: 
        }
    }
}
