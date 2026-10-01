#include "matcher.h"
#include <iostream>
#include <string>
#include <cassert>

void runTests() {
    auto res = PatternMatcher::findAll("abacb", "a*b");
    assert(res.size() == 3);
}

std::string genData(int size) {
    std::string res;
    for(int i = 0; i < size; ++i) res += "abc";
    return res;
}

int main() {
    runTests();
    std::string text = genData(600);
    std::string pat = "a*c";
    
    int matches = 0;
    for(int i = 0; i < 20; ++i) {
        auto res = PatternMatcher::findAll(text, pat);
        matches = res.size();
    }
    
    std::cout << matches << "\n";
    return 0;
}
