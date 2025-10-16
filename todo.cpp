#include <iostream>
#include <iomanip>
#include "todo.h"
using namespace std; 


todo::todo() {
    this->id = -1;
    this->content = ""; 
}

todo::todo(int newID, string newContent) {
    this->id = newID; 
    this->content = newContent; 
}

int todo::getID() {
    return this->id; 
}

string todo::getContent() {
    return this->content;
}

void todo::setContent(string content) {
    this->content = content; 
}

void todo::setID(int id) {
    this->id = id; 
}

// prints the todo member variables to the ostream parameter
ostream &operator<<(ostream &os, const todo todo) {
    
    os << setw(8) << todo.id << setw(8)<< todo.content << endl; 
    
    return os; 
}


