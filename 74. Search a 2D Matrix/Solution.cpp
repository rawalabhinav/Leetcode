#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        vector <int> first(m.size());

        for(int i = 0; i < m.size(); ++i){
            first[i] = m[i][0];
        }

        auto it = lower_bound(first.begin(), first.end(), target);

        int i;
        if (it == first.end()){
            i = int(m.size()) - 1;
        } else if (*it == target){
            return true;
        } else {
            i = it - first.begin() - 1;
        }

    
        if (i < 0) return false;

        auto j = lower_bound(m[i].begin(), m[i].end(), target) - m[i].begin();
        if (j < m[i].size() && m[i][j] == target) {
            return true;
        }
        return false;  
    }
};