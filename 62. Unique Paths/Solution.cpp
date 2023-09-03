#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Or you can just find C(n + m - 2, n - 1);
        vector <int> dp(n, 1);

        for(int i = 1; i < m; ++i){
            for(int j = n - 2; j > -1; --j){
                dp[j] += dp[j + 1];
            }
        }
        
        return dp[0];
    }
};