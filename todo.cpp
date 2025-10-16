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


