#include <iostream>
#include <string> // Working with strings
#include <vector>
#include <sstream>
#include <iterator>
#include <queue>

using namespace std; //Namespace std so that std::cout is just cout.

pair<string, string> module;
vector<pair<string, string>> modules;
vector<string> words;
vector<pair<string, string>> processedStrings;
vector<pair<string, string>> connectedModules;

#pragma region Operations

namespace Operations {
    enum Type {
        echo = 1,
        reverse = 2,
        delay = 3,
        noop = 4
    };
} typedef Operations::Type Operation;

string echo(string word)
{
    return word + word;
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
    vector<string> tempWords;
    for (string word : words) {
        tempWords.push_back(word);
    }
    return tempWords[tempWords.size() - 2];
}

string noop(string word)
{
    return word;
}

#pragma endregion

void createModule(string name, string operation) {

    module.first = name;
    module.second = operation;
    modules.push_back(module);
}

void connectModules(string first_module, string second_module) {
    pair<string, string> connection;
    connection.first = first_module;
    connection.second = second_module;

    connectedModules.push_back(connection);
}

/*
*   Method that processes the user input strings and prints out in the cmd.
*   <input> expects the process input from user
*/
void processString(string input) {
    string word;                 // Have a buffer string
    stringstream ss(input);       // Insert the string into a stream

    vector<string> inputWords; // Create vector to hold our words

    pair<string, string> modulesString; // temporary holds the modules while changing their output
    vector<pair<string, string>> processingModules = modules; // variable that holds the created modules and change them while processing

    /*
    *   <inputWords> Holds each word that is not "process" into the vector
    */
    while (getline(ss, word, ' ')) {
        if (word != "process") {
            inputWords.push_back(word);
        }
    }

    /*
    *   for every word we pair them with the respective module and we process the word with respective module operation
    *   <first_module> <first_word>
    *   <second_module> <second_word>
    *   ...
    */
    for (int i = 0; i < inputWords.size(); i++) {
        modulesString.first = processingModules[i].first;

        if (processingModules[i].second == "echo") {
            modulesString.second = echo(inputWords[i]);
        }
        else if (processingModules[i].second == "reverse") {
            modulesString.second = reverse(inputWords[i]);
        }
        else if (processingModules[i].second == "delay") {
            if (i == 0) {
                modulesString.second = inputWords[0];
            }
            else {
                modulesString.second = inputWords[i - 1];
                processingModules[i].second = processingModules[i - 1].second;
            }
        }
        else if (processingModules[i].second == "noop") {
            modulesString.second = noop(inputWords[i]);
        }

        #pragma region Connect
            /*
            *   for every pair of connected modules check if the <first_module> of processing is inside <connectedModules>
            *   <first_module> <first_word>
            *   <second_module> <second_word>
            *   ...
            */
            for (pair<string, string> conModule : connectedModules)
            {
                /*
                *   if the <first_module> of processingModules is equals to <first_module> of connectedModules
                *   make the output(.second) of the [i] module to the input of [j] module
                */
                if (processingModules[i].first == conModule.first) {
                    for (int j = 0; j < processingModules.size(); j++) {
                        if (processingModules[j].first == conModule.second) {
                            processingModules[j].second = processingModules[i].second;
                        }
                    }
                }
            }

            processedStrings.push_back(modulesString); //save the changed strings(words) into the vector
        #pragma endregion

    }

    cout << "\n added modules: \n";
    for (pair<string, string> module : modules) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n connected modules: \n";
    for (pair<string, string> module : connectedModules) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n processing modules: \n";
    for (pair<string, string> module : processingModules) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n processedStrings: \n";
    for (pair<string, string> module : processedStrings) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n Result: \n";
    for (pair<string, string> module : processedStrings) {
        cout << module.second + " ";
    }
}

#pragma region Split User Input

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

#pragma endregion

void interactive_command()
{
    /*
    *   <command> expects an input like module, connect, process and exit.
    *   <input> expects the process input from user
    */
    string command, input;

    /*
    *   The first word that will be processed is "hello".
    *   <initialWord> Here we add the hello word to the vector by initializing it with a pair<string, string>
    */
    pair<string, string> initialWord;
    initialWord.first = "initial";
    initialWord.second = "hello";
    processedStrings.push_back(initialWord);

    cout << "Hello! Please write the command: \n";
    cout << "To add a module: module <module_name> <operation>\n";
    cout << "To do a connection between two modules: connect <first_module_name> <second_module_name>\n";
    cout << "To process the strings(words): process <first_word> <second_word>\n";

    do
    {
        /*
        *   <getline> method gets the user input from cmd and saves it inside a variable.
        *   <input> variable that holds user input
        */
        getline(cin, input);

        /*
        *   <SplitUserInput> method gets the user input and returns the command.
        *   <command> variable that holds command from user input
        */
        command = SplitUserInput(0, input);

        if (command == "module") // module <name> <operation>
        {
            createModule(SplitUserInput(1, input), SplitUserInput(2, input));
        }
        else if (command == "connect") // connect <first_module_name> <second_module_name>
        {
            connectModules(SplitUserInput(1, input), SplitUserInput(2, input));
        }
        else if (command == "process") // processes commands with given strings.
        {
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
