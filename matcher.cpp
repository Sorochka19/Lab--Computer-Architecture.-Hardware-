#include "matcher.h"

bool PatternMatcher::matchChar(const std::string& t, int tS, int tE, const std::string& p, int pI) {
    if (pI == p.size()) return tS == tE;
    if (tS == tE) return p[pI] == '*' && matchChar(t, tS, tE, p, pI + 1);
    if (p[pI] == '*') return handleStar(t, tS, tE, p, pI);
    if (t[tS] == p[pI]) return matchChar(t, tS + 1, tE, p, pI + 1);
    return false;
}

bool PatternMatcher::handleStar(const std::string& t, int tS, int tE, const std::string& p, int pI) {
    if (matchChar(t, tS, tE, p, pI + 1)) return true;
    if (tS < tE) return matchChar(t, tS + 1, tE, p, pI);
    return false;
}

void PatternMatcher::checkSubs(const std::string& t, const std::string& p, int i, std::vector<Match>& r) {
    for (size_t j = i + 1; j <= t.size(); ++j) {
        if (matchChar(t, i, j, p, 0)) r.push_back({i, (int)(j - i)});
    }
}

std::vector<Match> PatternMatcher::findAll(const std::string& t, const std::string& p) {
    std::vector<Match> res;
    for (size_t i = 0; i < t.size(); ++i) checkSubs(t, p, i, res);
    return res;
}
