#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <vector <int>> m;
    string a;

    int help(int i, int j){
        if (i > j) return 0;

        if (i == j) return m[i][j] = 1;

        if (m[i][j] != -1) return m[i][j];

        int x = 0,  y = 0, z = 0;
        if (a[i] == a[j]) x = 2 + help(i + 1, j - 1);
        else {
            y = help(i + 1, j);
            z = help(i, j - 1);
        }

        return m[i][j] = max(x, max(y, z));
    }
    int longestPalindromeSubseq(string s) {
        a = s;
        int n = s.size();

        m.assign(n, vector <int> (n, -1));
        return help( 0, (int) n - 1);
    }
};