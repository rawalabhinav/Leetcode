#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int f[26]{};

        for(char& c: s) ++f[c - 'a'];
        for(char& c: t) --f[c - 'a'];

        int ans = 0;
        for(int& e: f) ans += abs(e);
        return ans / 2;
    }
};