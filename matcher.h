#ifndef MATCHER_H
#define MATCHER_H
#include <string>
#include <vector>

struct Match {
    int start;
    int length;
};

class PatternMatcher {
public:
    static std::vector<Match> findAll(const std::string& text, const std::string& pat);
private:
    static void checkSubs(const std::string& t, const std::string& p, int i, std::vector<Match>& r);
    static bool handleStar(const std::string& t, int tS, int tE, const std::string& p, int pI);
    static bool matchChar(const std::string& t, int tS, int tE, const std::string& p, int pI);
};

#endif
