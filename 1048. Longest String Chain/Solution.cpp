#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int predecessor(string& s, string& t){
        int j = 0;
        for(; j + 1 < t.size() && (t[j] == s[j]); ++j);
        for(; j + 1 < t.size() && (t[j + 1] == s[j]); ++j);
        return (j + 1 == t.size());    
    }

    int longestStrChain(vector<string>& w) {
        int n = w.size();

        vector <int> b[17];
        for(int i = 0; i < n; ++i){
            b[w[i].size()].emplace_back(i);
        }

        vector <int> dp(n, 1);
        for(int i = 16; i > 1; --i){
            if (b[i].size() == 0 or b[i - 1].size() == 0){
                continue;
            }

            for(auto& big: b[i]){
                for(auto& smol: b[i - 1]){
                    if (predecessor(w[smol], w[big])){
                        dp[smol] = max(dp[smol], dp[big] + 1);
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};