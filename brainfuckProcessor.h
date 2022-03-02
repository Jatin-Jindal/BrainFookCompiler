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
            if (s < 0 || s > 1) return false;
        }
        return s == 0;
    }

    void computeLoop(std::queue<char> loop) {
        std::string l;
        while (!loop.empty()) { l += loop.front(); loop.pop(); }
        u_char ch;
        int loopAdd = p;
        while (memory[loopAdd] != 0) {
            for (auto c: l) {
                if (c == '>') p = (p == 30000) ? 30000 : p+1;
                else if (c == '<') p = (p == 00000) ? 00000 : p-1;
                else if (c == '+') memory[p]++;
                else if (c == '-') memory[p]--;
                else if (c == '.') putchar(memory[p]);
                else if (c == ',') { std::cin >> ch; memory[p] = int(ch); }
            }
        }
    }

public:
    BrainfuckProcessor() = default;

    BrainfuckProcessor(std::string input) {
        code = std::move(input);
        if (!valid()) throw std::runtime_error("Invalid code");
    }

    void run() {
        parse();
    }

    ~BrainfuckProcessor() = default;
};


void BrainfuckProcessor::parse() {
    std::queue<char> loop;
    int loopPtr;
    int inLoop = 0; // 0 = outside loop, 1 = inside loop, 2 = skip loop
    u_char ch;
    for (auto c: code) {
        if (inLoop == 2);
        else if (inLoop == 1) { loop.push(c); }
        else if (c == '>') p = (p == 30000) ? 30000 : p+1;
        else if (c == '<') p = (p == 00000) ? 00000 : p-1;
        else if (c == '+') memory[p]++;
        else if (c == '-') memory[p]--;
        else if (c == '.') putchar(memory[p]);
        else if (c == ',') { std::cin >> ch; memory[p] = int(ch); }
        else if (c == '[') {
            if (memory[p] != 0) {
                inLoop = 1;
                loopPtr = p;
            } else { inLoop = 2; }
        }
        else if (c == ']') { inLoop = 0; computeLoop(loop); }
    }
}