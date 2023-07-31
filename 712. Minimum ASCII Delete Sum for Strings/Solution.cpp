#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector <vector<int>> memo;
    vector <int> pre1, pre2;

    int helper(int i, int j, string& s1, string& s2){
        if (i == n){
            return pre2[j];
        }

        if (j == m){
            return pre1[i];
        }

        if (memo[i][j] < 1000000) return memo[i][j];
        int x = 1000000, y, z;

        if (s1[i] == s2[j]) x = helper(i + 1, j + 1, s1, s2);
        y = int(s1[i]) + helper(i + 1, j, s1, s2);
        z = int(s2[j]) + helper(i, j + 1, s1, s2);

        return memo[i][j] = min(min(y, z), x);
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size(), m = s2.size();

        memo.resize(n, vector <int>(m, 1000000));
        pre1.resize(n + 1), pre2.resize(m + 1);

        for(int i = n - 1; i > -1; --i){
            pre1[i] = pre1[i + 1] + s1[i];
        }

        for(int i = m - 1; i > -1; --i){
            pre2[i] = pre2[i + 1] + s2[i];
        }

        return helper(0, 0, s1, s2);
    }
};