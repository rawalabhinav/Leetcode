#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector <vector<int>> dp;
    string s1, s2, s3;

    bool help(int i, int j){
        if (dp[i][j] > -1) return dp[i][j];
        dp[i][j] = false;

        if (i < n && s1[i] == s3[i + j]){
            dp[i][j] = help(i + 1, j);
        }

        if (j < m && s2[j] == s3[i + j]){
            dp[i][j] = dp[i][j] or help(i, j + 1);
        }

        return dp[i][j];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()){
            return false;
        }

        n = s1.length(), m = s2.length();
        dp.resize(n + 1, vector <int>(m + 1, -1));
        dp[n][m] = 1;

        this -> s1 = s1, this -> s2 = s2, this -> s3 = s3;
        return help(0, 0);
    }
};