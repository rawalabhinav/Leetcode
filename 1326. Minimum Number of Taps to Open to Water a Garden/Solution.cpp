#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector <pair <int, int>> p, f;
        for(int i = 0; i <= n; ++i){
            p.push_back({max(0, i - ranges[i]), -min(n, i + ranges[i])});
        }

        sort(p.begin(), p.end());

        auto [l, r] = p[0]; 
        f.push_back(p[0]);
        for(int i = 1; i <= n; ++i){
            if (p[i].first > -r) return -1;

            // filter nested ranges
            if (p[i].first > l and -p[i].second > -r){
                f.push_back(p[i]);
                tie(l, r) = p[i];
            }
        }

        tie(l, r) = p[0];
        int ans = 1;
        f.push_back({n + 1, -n - 1});

        if (r == -n) return 1;
        for(int i = 1; i < f.size(); ++i){
            for(; f[i].first <= -r; ++i);
            tie(l, r) = f[i - 1]; 
            ++ans;
        }

        return (r == -n) ? ans : -1;
    }
};