#include <iostream>
using namespace std; 

/* An element of a to-do list */
class todo {
    public: 
        int getID(); 
        string getContent(); 
        void setContent(string); 
        void setID(int); 
        
        todo();
        todo(int, string); 
        
        
        
    private:
        int id; 
        string content; 
};