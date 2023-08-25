#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()){
            return false;
        }

        int n = s1.length(), m = s2.length();
        vector <int> dp(m + 1, -1);
        dp[m] = 1;

        for(int i = n; i > -1; --i){
            for(int j = m - (i == n); j > -1; --j){
                int down = dp[j];
                dp[j] = 0;

                if (i < n && s1[i] == s3[i + j]){
                    dp[j] = down;
                }

                if (j < m && s2[j] == s3[i + j]){
                    dp[j] = dp[j] or dp[j + 1];
                }
            }
        }
        return dp[0];
    }
};