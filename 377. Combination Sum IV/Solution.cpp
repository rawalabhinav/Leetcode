#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& a, int t) {
        vector <unsigned long long> dp(t + 1);
        dp[0] = 1;

        for(int i = 0; i < t; ++i){
            for(int j = 0; j < a.size(); ++j){
                if (i + a[j] <= t) {
                    dp[i + a[j]] += dp[i];
                }
            }
        }

        return dp[t];
    }
};