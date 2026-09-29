#include "matcher.h"
#include <iostream>
#include <string>
#include <cassert>

void runTests() {
    auto res = PatternMatcher::findAll("abacb", "a*b");
    assert(res.size() == 2);
}

std::string genData(int size) {
    return std::string(size, 'a') + "b";
}

int main() {
    runTests();
    std::string text = genData(3000); 
    std::string pat = "a*a*a*b";
    auto res = PatternMatcher::findAll(text, pat);
    std::cout << res.size() << "\n";
    return 0;
}
