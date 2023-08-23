#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int f[26]{0};
        string ans = s;

        for(char& e: s) ++f[e - 'a'];
        if (*max_element(f, f + 26) > (n + 1) / 2){
            return "";
        }

        vector <pair<int, int>> v;
        for(int i = 0; i < 26; ++i){
            v.push_back({-f[i], i});
        }

        sort(v.begin(), v.end());
        int even = 0, odd = 1;
        for(auto&[freq, i]: v){
            for(int j = 0; j < -freq; ++j){
                if (even < n){
                    ans[even] = 'a' + i;
                    even += 2;
                } else {
                    ans[odd] = 'a' + i;
                    odd += 2;
                }
            }
        }

        return ans;
    }
};