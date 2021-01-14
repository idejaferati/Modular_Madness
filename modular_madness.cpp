#include <iostream>
#include <string> // Working with strings
#include <vector>
#include <sstream>
#include <iterator>

using namespace std; //Namespace std so that std::cout is just cout.

void interactive_command();

int main()
{
    interactive_command(); // Calls interactive_command() with an infinte loop that exits when the given commad is exit.
    
    const string delimiter = " ";
}

void interactive_command()
{
    string command;

    do
    {
        cin >> command;

        switch (command) {
        case "echo":
            //TODO 

            // cout << "echo" << endl; // Prints echo when called, used in early testing
            break;
        case "process":
            //TODO

            // cout << "process"<<endl;
            break;
        case "reverse":
            //TODO

            // cout << "reverse"<<endl;
            break;
        case "delay":
            //TODO

            // cout << "delay"<<endl;
            break;
        case "noop":
            //TODO

            // cout << "noop"<<endl;
            break;
        }

    } while (command != "exit");
}


//https://stackoverflow.com/questions/3955601/how-do-i-split-a-string-at-an-arbitrary-index