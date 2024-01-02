#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& a) {
        int n = a.size(), row = 0;

        set <int> s;
        vector <int> f(n + 1);

        for(int& e: a) {
            s.insert(e);
            ++f[e];
            row = max(row, f[e]);
        }

        vector <vector <int>> ans(row);
        for(int i = 0; i < row; ++i){
            vector <int> erase;

            for(const int& e: s){
                ans[i].emplace_back(e);
                if (--f[e] == 0) erase.emplace_back(e);
            }

            for(int& e: erase) s.erase(e);
        }

        return ans;


    }
};