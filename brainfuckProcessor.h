//
// Created by jatin on 26-02-2022.
//

#ifndef BRAINFOOK_COMPILER_BRAINFUCKPROCESSOR_H
#define BRAINFOOK_COMPILER_BRAINFUCKPROCESSOR_H

#endif //BRAINFOOK_COMPILER_BRAINFUCKPROCESSOR_H

#include <bits/stdc++.h>


class BrainfuckProcessor {
    std::string code;
    int memory[30000] = {0};
    int p = 0;

    void parse();

    bool valid() {
        // Check if [] are balanced
        int s = 0;
        for (auto c: code) {
            if (c == '[') s++;
            if (c == ']') s--;
            if (s < 0) return false;
        }
        return s == 0;
    }

    void computeLoop(std::string loop) {
        int P = p;
        while (memory[P] != 0) {
            int i = 0;
            while (i < loop.length()) {
                char c = loop[i];
                if (c == '+') memory[p]++;
                if (c == '-') memory[p]--;
                if (c == '>') p++;
                if (c == '<') p--;
                if (c == '.') std::cout << (char) memory[p];
                if (c == ',') {
                    u_char s;
                    std::cin >> s;
                    memory[p] = s;
                }
                if (c == '[') {
                    int n = 1, j = i;
                    while (n != 0) {
                        j++;
                        if (loop[j] == '[') n++;
                        if (loop[j] == ']') n--;
                    }
                    std::string loop2 = code.substr(i + 1, j - i - 1);
                    i = j;
                    computeLoop(loop2);
                }
            }
            i++;
        }
    }

public:
    BrainfuckProcessor() = default;

    explicit BrainfuckProcessor(std::string input) {
        code = std::move(input);
        if (!valid()) throw std::runtime_error("Invalid code");
    }

    void run() {
        parse();
    }

    ~BrainfuckProcessor() = default;
};


void BrainfuckProcessor::parse() {
////    std::queue<char> loop;
//    std::string loop;
//    int inLoop = 0; // 0 = outside loop, 1 = inside loop, 2 = skip loop
//    u_char ch;
//    int n = 0;
//    for (auto c: code) {
//        if (inLoop == 2);
//        else if (inLoop == 1 && c != ']') {
//            n += (c == '[');
//            loop += c;
//        } else if (c == '>') p = (p == 30000) ? 30000 : p + 1;
//        else if (c == '<') p = (p == 00000) ? 00000 : p - 1;
//        else if (c == '+') memory[p]++;
//        else if (c == '-') memory[p]--;
//        else if (c == '.') putchar(memory[p]);
//        else if (c == ',') {
//            std::cin >> ch;
//            memory[p] = int(ch);
//        }
//        else if (c == '[') {
//            n++;
//            if (memory[p] != 0) inLoop = 1;
//            else inLoop = 1;
//        } else if (c == ']') {
//            if (--n == 0) {
//                inLoop = 0;
//                computeLoop(loop);
//            }
//        }
//    }
    int i = 0;
    while (i < code.length()) {
        char c = code[i];
        if (c == '+') memory[p]++;
        if (c == '-') memory[p]--;
        if (c == '>') p++;
        if (c == '<') p--;
        if (c == '.') std::cout << (char)memory[p];
        if (c == ',') {
            u_char s;
            std::cin >> s;
            memory[p] = s;
        }
        if (c == '[') {
            int n = 1, j = i;
            while (n != 0 && j < code.length()) {
                j++;
                if (code[j] == '[')
                    n++;
                if (code[j] == ']')
                    n--;
            }
            std::string loop = code.substr(i+1, j - i - 1);
            i = j;
            computeLoop(loop);
        }
        i++;
    }
}