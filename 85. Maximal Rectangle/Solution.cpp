#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getArea(vector<int>& h) {
        int n = h.size();
        int ans = 0;

        stack <pair<int, int>> s;
        for(int j = 0; j < n; ++j){
            int left = 0;
            while(!s.empty() && h[j] <= h[s.top().first]){
                auto [i, l] = s.top();

                ans = max(ans, (j - i + l) * h[i]);
                s.pop();
                left += l + 1;
            }

            s.push({j, left});
        }

        return ans;   
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;

        vector <int> dp(m + 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                (mat[i][j] == '0') ? dp[j] = 0 : ++dp[j];
            }

            ans = max(getArea(dp), ans);
        }

        return ans;
    }
};