#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

class Solution {
public:
    int dp[20]{};

    Solution(){
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
    }

    int numTrees(int n) {
        if (dp[n]) return dp[n];

        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += numTrees(i) * numTrees(n - i - 1);
        }

        return dp[n] = sum;       
    }
};