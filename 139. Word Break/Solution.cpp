#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    string s;
    vector <vector <int>> memo;

    // s index, j where last string was cut
    int f(int i, int j, multiset <string>& m){
        if (i == n && j == n) return 1;
        if (i == n or i - j + 1 > 20) return 0;

        if (memo[i][j] > -1) return memo[i][j];

        memo[i][j] = 0;
        if (m.find(s.substr(j, i - j + 1)) != m.end()){
            memo[i][j] = f(i + 1, i + 1 , m);
        }

        return memo[i][j] |= f(i + 1, j, m);
    }

    bool wordBreak(string s, vector<string>& dict) {
        this -> s = s;
        n = s.length();
        memo.resize(n, vector <int>(n, -1));
        
        multiset <string> m(dict.begin(), dict.end());
        return f(0, 0, m);
    }
};