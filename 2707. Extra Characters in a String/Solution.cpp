#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string a;
    int n;
    vector <vector <int>> dp;
    int f(int i, int j, unordered_set <string>& s){
        if (j == n) return n - i;

        if (dp[i][j] != 100) return dp[i][j];
        if (s.find(a.substr(i, j - i + 1)) != s.end()){
            dp[i][j] = f(j + 1, j + 1, s);
        } else {
            dp[i][j] = j - i + 1 + f(j + 1, j + 1, s);
        }

        dp[i][j] = min(dp[i][j], f(i, j + 1, s));
        return dp[i][j];
    }

    int minExtraChar(string a, vector<string>& d) {
        this -> a = a;
        n = a.length();
        unordered_set <string> s(d.begin(), d.end());
        dp.assign(n, vector <int>(n, 100));
        return f(0, 0, s);
    }
};