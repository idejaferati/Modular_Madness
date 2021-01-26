#include <iostream>
#include <string> // Working with strings
#include <vector>
#include <sstream>
#include <iterator>
#include <map>

using namespace std; //Namespace std so that std::cout is just cout.

pair<string, string> module;
vector<pair<string, string>> modules;
vector<string> words;
vector<pair<string, string>> processedStrings;

string echo(string word)
{
    return word+word;
}

string reverse(string word)
{
    string reverse_word = word;
    int length = word.length();
    int last = length - 1;

    for (int i = 0; i < (length / 2); i++) {
        swap(reverse_word[i], reverse_word[last]);
        last = last - 1;
    }
    
    return reverse_word;
}

string delay(vector<string> words)
{
    return words[words.size()-1];
}

string noop(string word)
{
    return word;
}


void createModule(string name, string operation) {

    module.first = name;
    module.second = operation;
    if (modules.empty()) {
        modules.push_back(module);
    }
    else {
        modules.clear();
        modules.push_back(module);
    }
}

static void moduleCommandRun() {
    string nameOfModule;
    cin >> nameOfModule;

    string operation;
    cin >> operation;

    createModule(nameOfModule, operation);
}


void connectModules(string first_module, string second_module) {
    string firstWord;
    string secondWord;

    for (pair<string, string> module : processedStrings) {
        firstWord = module.second;
        secondWord = module.first;
    }

    if (module.first == first_module) {
        cout << firstWord + secondWord;
    }
    else {
        cout << secondWord + firstWord;
    }
}

void connectCommandRun() {
    string first_module;
    cin >> first_module;

    string second_module;
    cin >> second_module;

    connectModules(first_module, second_module);
}


void interactive_command()
{
    char test[200]; 
    char test2[200];
    char test3[200];
    string command, argument1, argument2, argument3, argument4; // command expects an input like module, connect, process and exit, argumets1-4 expect strings and names or modules.

    do
    {

        // write first module
        // write second module
        // write operation
        // process result


        // [module, name, operation] -> matrix of module
        // [connect, module_name, module_name] -> array of connect
        // [process, keyword1, keyword2] -> array of process


        //char name[256], title[256];

        //cout << "Enter your name: ";
        //cin.getline(name, 256);
        //cout << name;
        //cout << "Enter your favourite movie: ";
        //cin.getline(title, 256);

        //cout << name << "'s favourite movie is " << title;

        //cin >> command >> argument1 >> argument2;//>>argument3>>argument4; //NEEDED a way to figure reading input till 'ENTER' is pressed
        
        cout << "Hello! Please write the command: \n";

        cin >> command;

        if (command == "module") // module <name> <operation>
        {
            moduleCommandRun();
        }
        else if (command == "connect")
        {
            //TODO
            connectCommandRun();
        }
        else if (command == "process") // processes commands with given strings.
        {
            //TODO save the inputs

        }

    } while (command != "exit");
}

int main()
{
    interactive_command(); // Calls interactive_command() with an infinte loop that exits when the given commad is exit.
}


//This comes in handy when using reverse() because everycharacter needs to be indexed to an array and then called in reverse.
//https://stackoverflow.com/questions/3955601/how-do-i-split-a-string-at-an-arbitrary-index
