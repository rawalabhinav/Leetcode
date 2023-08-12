#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        vector <long> dp(m + 1);
        dp[m - 1] = 1;

        for(int i = n - 1; i > -1; --i){
            for(int j = m - 1; j > -1; --j){
                dp[j] = (!g[i][j]) * (dp[j] + dp[j + 1]);
            }
        }

        return dp[0];
    }
};