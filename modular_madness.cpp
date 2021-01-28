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

int connections[100][100];

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
    
    return "\n"+ reverse_word;
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
    modules.push_back(module);
}

string SplitUserInput(int n, string wholeCommand) {
    string argument;
    size_t pos1 = 0, pos2 = 1;

    while (n >= 0) { // positive indexing only
        if (pos2 >= wholeCommand.length())
            return string();
        pos2 = wholeCommand.find(" ", pos1); //finds the first argument
        argument = wholeCommand.substr(pos1, pos2 - pos1); //gets the argument splitted by space as a delimiter
        pos1 = pos2 + 1;
        n--;
    }

    return argument;
}

void connectModules(string first_module, string second_module) {
    int intA = -1; //index of module with name a in modules array
    int intB = -1; //index of module with name b in modules array
    //finding a and b in the modules
    for (int i = 0; i <= modules.size(); i++) {
        if (first_module.compare(modules[i].first) == 0)
            intA = i;
        if (second_module.compare(modules[i].first) == 0)
            intB = i;
        if (intA != -1 && intB != -1)
            break;
    }
    //second index for connections
    int c = 0;
    while (connections[intA][c] != -1 && c < 100) {
        c++;
    }
    connections[intA][c] = intB;
}
void processArgument(string argument) // processes argument 
{
    // TODO process argument
}

// If modules are not empty then continue to process strings
//bool modulesNotEmpty() {
//    for (int i = 0; i < modules.size(); i++) {
//        if (!modules[i].words.empty())
//            return true;
//    }
//    return false;
//}

void processString(string input) {
    int n = 1;
    string argument = SplitUserInput(n, input);

    while (!argument.empty()) {
        processArgument(argument);
        n++;
        argument = SplitUserInput(n, input);
    }
    //If modules are not empty then process them with an empty string
    /*while (modulesNotEmpty())
        processArgument("");*/
}

void interactive_command()
{
    string command, input, argument1, argument2, argument3, argument4; // command expects an input like module, connect, process and exit, argumets1-4 expect strings and names or modules.

    cout << "Hello! Please write the command: \n";

    //At the start of the program write all connections with -1, later used to index them.
	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 100; y++) {
			connections[x][y] = -1;
		}
	}

    do
    {
        getline(cin, input);

        command = SplitUserInput(0, input);
        
        if (command == "module") // module <name> <operation>
        {
            createModule(SplitUserInput(1, input), SplitUserInput(2, input));
        }
        else if (command == "connect")
        {
            //TODO
            connectModules(SplitUserInput(1, input), SplitUserInput(2, input));
        }
        else if (command == "process") // processes commands with given strings.
        {
            //TODO save the inputs
            processString(input);
        }
        else if (command == "exit") {
            modules.clear();
        }

    } while (command != "exit");
}

int main()
{
    interactive_command(); // Calls interactive_command() with an infinte loop that exits when the given commad is exit.
}


//This comes in handy when using reverse() because everycharacter needs to be indexed to an array and then called in reverse.
//https://stackoverflow.com/questions/3955601/how-do-i-split-a-string-at-an-arbitrary-index 
