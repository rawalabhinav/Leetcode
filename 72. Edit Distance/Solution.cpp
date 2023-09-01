#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        if (m > n){
            swap(s, t); swap(n, m);
        }
    
        vector <int> dp(m + 1);
        iota(dp.rbegin(), dp.rend(), 0ll);
        
        for(int i = n - 1; i > -1; dp[m] = n - i, --i){
            int old = dp[m];
    
            for(int j = m - 1; j > -1; --j){
                int current = dp[j];
    
                dp[j] = min(dp[j + 1] + 1, min(dp[j] + 1, old + (s[i] != t[j])));
    
                old = current;
            }
        }
        return dp[0];
    }
};