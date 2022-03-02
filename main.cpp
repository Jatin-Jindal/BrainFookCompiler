#include <bits/stdc++.h>
#include <unistd.h>
#include "brainfuckProcessor.h"

#define iCase regex_constants::icase

using namespace std;

bool isBrainFuckCharacter(char letter);

string getBrainFuckCode(ifstream &in);

bool isValidCall(int argc, char const *argv[]);

bool isAscii(int x) {
    return x >= 0 && x <= 127;
}

bool isFileEmpty(ifstream &in) {
    return in.peek() == ifstream::traits_type::eof();
}

int main(int argc, char const *argv[]) {

    // Check if the call is valid
    if (!isValidCall(argc, argv))
        return 1;

    // After all the checks, we can open the file
    // Checking if the file is empty
    ifstream file(argv[1]);
    if (isFileEmpty(file)) {
        cout << "File is empty" << endl;
        return 1;
    }

    // Get the code
    string code = getBrainFuckCode(file);
    file.close();

    // TODO: PARSE CODE HERE
    BrainfuckProcessor processor(code);
    processor.run();

    cout << "Code: \'" << code << '\'';

    return 0;
}

string getBrainFuckCode(ifstream &in) {
    // Returns the code without the comments
    string code;
    char c;

    while (in.get(c))
        if (isBrainFuckCharacter(c))
            code += c;

    return code;
}

bool isBrainFuckCharacter(char letter) {
    // Returns true if the character is a valid Brainfuck character (i.e. +-<>.,[]).
    return letter == '>' || letter == '<' || letter == '+' || letter == '-' || letter == '.' || letter == ',' ||
           letter == '[' || letter == ']';
}

bool isValidCall(int argc, char const *argv[]) {

    // Check if there is a file
    if (argc != 2)
        cout << "Usage: " << argv[0] << " <input_file>" << endl;

        // Check if the file is a brainfuck file
    else if (!regex_match(argv[1], regex(R"(^(.*[\\\/]|)[a-z_][a-z_0-9 ]*\.bf$)", iCase))) {
        cout << "Invalid file name" << endl;
        cout << "Enter a valid Brainfuck file name (*.bf)" << endl;
    }

        // Check if the file exists
    else if (access(argv[1], F_OK) == -1)
        cout << "File does not exist" << endl;

        // Check if the file is readable
    else if (access(argv[1], R_OK) == -1)
        cout << "File is not readable" << endl;

        // If any of the above conditions are not met, return 0
    else {
        cout << "FILE FOUND!" << endl;
        return true;
    }
    return false;
}
