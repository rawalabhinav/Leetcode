#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string s, string t) {
        int n = s.length();

        if (n != t.length()) return false;
        int fs[26]{}, ft[26]{};

        for(char& c: s) ++fs[c - 'a'];
        for(char& c: t) ++ft[c - 'a'];

        for(int i = 0; i < 26; ++i){
            if (bool(fs[i]) != bool(ft[i])) return false;
        }

        sort(fs, fs + 26);
        sort(ft, ft + 26);

        for(int i = 0; i < 26; ++i){
            if (fs[i] != ft[i]) return false;
        }

        return true;
    }
};