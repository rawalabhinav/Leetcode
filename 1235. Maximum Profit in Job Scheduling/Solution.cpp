#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        vector <array <int, 3>> a(n);
        for(int i = 0; i < n; ++i){
            a[i] = {s[i], e[i], p[i]};
        }
        
        sort(a.begin(), a.end());
        vector <int> dp(n);

        dp.back() = a.back()[2];
        set <pair<int, int>> d;
        d.insert({a.back()[0], n - 1});

        for(int i = n - 2; i > -1; --i){
            auto it = d.lower_bound({a[i][1], i});

            if (it != d.end()){
                dp[i] = max(dp[i + 1], a[i][2] + dp[it -> second]);
            } else {
                dp[i] = max(a[i][2], dp[i + 1]);
            }

            d.insert({a[i][0], i});
        }
        return dp[0];

    }
};