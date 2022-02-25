#include <bits/stdc++.h>
#include <unistd.h>


using namespace std;

bool isAscii(int x) {
    return x >= 0 && x <= 127;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    } else if (!regex_match(argv[1], regex(R"(^(.*[\\\/]|)[a-zA-Z_][a-zA-Z_0-9 ]*\.bf$)"))) {
        cout << "Invalid file name" << endl;
        cout << "Enter a valid Brainfuck file name (*.bf)" << endl;
        return 1;
    } else if (access(argv[1], F_OK) == -1) {
        cout << "File does not exist" << endl;
        return 1;
    } else if (access(argv[1], R_OK) == -1) {
        cout << "File is not readable" << endl;
        return 1;
    }
    cout << "FILE FOUND!" << endl;
    ifstream file(argv[1]);
    cout << file.rdbuf() << endl;
    file.close();
    return 0;
}
