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
        
        /* Prints the To-Do to the ostream */
        friend ostream& operator<<(ostream&, todo); 
        
        
        
    private:
        int id; 
        string content; 
};