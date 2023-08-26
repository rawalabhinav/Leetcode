#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int n) {
        int m = s.length();

        string ans = s;
        int d = max(2 * n - 2, 1), k = 0;

        for(int i = 0; i < n; ++i){
            for(int j = i; j < m; j += d){
                ans[k++] = s[j];

                if (i && i != n - 1 && j + d - 2 * i < m){
                    ans[k++] = s[j + d - 2 * i];
                }
            }
        }

        return ans;
    }
};