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
    string command, argument1, argument2, argument3, argument4; // command expects an input like module, connect, process and exit, argumets1-4 expect strings and names or modules.

    do
    {
        cin >>command>>argument1>>argument2;//>>argument3>>argument4; //NEEDED a way to figure reading input till 'ENTER' is pressed
        

        if (command == "module") // module <name> <operation>
        {
            string nameOfModule = argument1; //NEEDED a way to preserve previus entered modules in the network.
            string nameOfOperation = argument2; //one of these : "echo", "reverse", "delay", "noop".

            if(nameOfOperation == "echo")
            {
                echo();
            }
            else if (nameOfOperation == "reverse")
            {
                reverse();
            }
            else if (nameOfOperation == "delay")
            {
                delay();
            }
            else if (nameOfOperation == "noop")
            {
                noop();
            }
            else
            {
                break;
            }
            
            

        }
        else if (command == "connect")
        {
            //TODO

        }
        else if (command == "process") // processes commands with given strings.
        {
            //TODO

        }

    } while (command != "exit");
}

string echo()
{

}

string reverse()
{


}

string delay()
{

}
string noop()
{

}


//This comes in handy when using reverse() because everycharacter needs to be indexed to an array and then called in reverse.
//https://stackoverflow.com/questions/3955601/how-do-i-split-a-string-at-an-arbitrary-index 