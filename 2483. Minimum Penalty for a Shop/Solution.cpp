#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string s) {
        int score = 0, hour = -1, ans = 0;
        
        for(int i = 0; i < s.length(); ++i){
            score += s[i] == 'Y' ? 1 : -1;
            if (score > ans){
                hour = i, ans = score;
            }
        }

        return hour + 1;
    }
};