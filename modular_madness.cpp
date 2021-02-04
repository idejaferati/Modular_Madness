#include <iostream>
#include <string> // Working with strings
#include <vector>
#include <sstream>
#include <iterator>
#include <queue>

using namespace std; //Namespace std so that std::cout is just cout.

pair<string, string> module;
vector<pair<string, string>> modules;
pair<string, string> modulesString;
vector<string> words;
vector<pair<string, string>> processedStrings;
vector<pair<string, string>> connectedModules;

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

    pair<string, string> connection;
    connection.first = first_module;
    connection.second = second_module;

    connectedModules.push_back(connection);

    //int intA = -1; //index of module with name a in modules array
    //int intB = -1; //index of module with name b in modules array
    ////finding a and b in the modules
    //for (int i = 0; i <= moduless.size(); i++) {
    //    if (first_module.compare(moduless[i].first) == 0)
    //        intA = i;
    //    if (second_module.compare(moduless[i].first) == 0)
    //        intB = i;
    //    if (intA != -1 && intB != -1)
    //        break;
    //}
    ////second index for connections
    //int c = 0;
    //while (connections[intA][c] != -1 && c < 100) {
    //    c++;
    //}
    //connections[intA][c] = intB;

    //cout << connections;
}
void processString(string input) {
    string word;                 // Have a buffer string
    stringstream ss(input);       // Insert the string into a stream

    vector<string> inputWords; // Create vector to hold our words

    vector<pair<string, string>> processingModules = modules;

    while (getline(ss, word, ' ')) {
        if (word != "process") {
            inputWords.push_back(word);
        }
    }

    cout << "\n modules: \n";
    for (int i = 0; i < inputWords.size(); i++) {
        modulesString.first = processingModules[i].first;

        /*goto*/A:
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

        //connection
        for (pair<string, string> conModule : connectedModules)
        {
            if (processingModules[i].first == conModule.first) {
                processingModules[i + 1].second = processingModules[i].second;
            }
        }

        processedStrings.push_back(modulesString);
    }

    cout << "\n added modules: \n";
    for (pair<string, string> module : modules) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n processing modules: \n";
    for (pair<string, string> module : processingModules) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n connected modules: \n";
    for (pair<string, string> module : connectedModules) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n processedStrings: \n";
    for (pair<string, string> module : processedStrings) {
        cout << "module: " + module.first + " " + module.second + "\n";
    }

    cout << "\n Rezultati: \n";
    for (pair<string, string> module : processedStrings) {
        cout << module.second + " ";
    }
}

void interactive_command()
{
    string command, input; // command expects an input like module, connect, process and exit, argumets1-4 expect strings and names or modules.

    cout << "Hello! Please write the command: \n";
    pair<string, string> initialWord;
    initialWord.first = "initial";
    initialWord.second = "hello";

    processedStrings.push_back(initialWord);
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
