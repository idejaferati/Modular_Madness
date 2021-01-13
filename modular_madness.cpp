#include <iostream>
#include <string> // Working with strings

using namespace std; //Namespace std so that std::cout is just cout.

void interactive_command();

int main()
{
    interactive_command(); // Calls interactive_command() with a infinte loop that exits when the given commad is exit.
    return 0;
}


void interactive_command()
{
    string command;

    do {        
        cin >> command;

        if (command == "echo")
        {
            //TODO


            // cout << "echo" << endl; // Prints echo when called, used in early testing
        }
        else if (command == "process")
        {
            //TODO



            // cout << "process"<<endl; 
        }
        else if (command == "reverse")
        {
            //TODO


            
            // cout << "reverse"<<endl; 
        }
        else if (command == "delay")
        {
            //TODO


            
            // cout << "delay"<<endl; 
        }
        else if (command == "noop")
        {
            //TODO


            
            // cout << "noop"<<endl; 
        }

    } while (command != "exit");
}