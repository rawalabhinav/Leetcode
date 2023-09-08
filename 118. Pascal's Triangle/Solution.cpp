#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector <vector< int>> ans(n);
        ans[0].emplace_back(1);

        for(int i = 1; i < n; ++i){
            ans[i].emplace_back(1);

            for(int j = 1; j < i; ++j){
                ans[i].emplace_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }

            ans[i].emplace_back(1);
        }

        return ans;
    }
};
