#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <vector <int>> m;
    string a;

    int help(int i, int j){
        if (i > j) return 0;
        if (m[i][j] != -1) return m[i][j];

        if (i == j) return m[i][j] = 1;
        if (a[i] == a[j]) return m[i][j] = 2 + help(i + 1, j - 1);
        return m[i][j] = max(help(i + 1, j), help(i, j - 1));
    }

    int longestPalindromeSubseq(string s) {
        a = s;
        int n = s.size();

        m.assign(n, vector <int> (n, -1));
        return help( 0, (int) n - 1);
    }
};