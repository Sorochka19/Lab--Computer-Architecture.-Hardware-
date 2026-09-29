#include "matcher.h"

bool PatternMatcher::matchChar(const std::string& t, const std::string& p, int tI, int pI) {
    if (pI == p.size()) return tI == t.size();
    if (tI == t.size()) return p[pI] == '*' && matchChar(t, p, tI, pI + 1);
    if (p[pI] == '*') return handleStar(t, p, tI, pI);
    if (t[tI] == p[pI]) return matchChar(t, p, tI + 1, pI + 1);
    return false;
}

bool PatternMatcher::handleStar(const std::string& t, const std::string& p, int tI, int pI) {
    if (matchChar(t, p, tI, pI + 1)) return true;
    if (tI < t.size()) return matchChar(t, p, tI + 1, pI);
    return false;
}

void PatternMatcher::checkSubs(const std::string& t, const std::string& p, int i, std::vector<Match>& r) {
    for (size_t j = i + 1; j <= t.size(); ++j) {
        if (matchChar(t.substr(i, j - i), p, 0, 0)) r.push_back({i, (int)(j - i)});
    }
}

std::vector<Match> PatternMatcher::findAll(const std::string& t, const std::string& p) {
    std::vector<Match> res;
    for (size_t i = 0; i < t.size(); ++i) checkSubs(t, p, i, res);
    return res;
}
