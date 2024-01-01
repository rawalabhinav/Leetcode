#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        for(int i = 0, j = 0; i < n && j < m; ++j){
            if (s[j] >= g[i]){
                ++ans; ++i;
            }
        }

        return ans;
    }
};