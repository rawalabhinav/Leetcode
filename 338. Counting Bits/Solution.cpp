#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n + 1);
        for(int i = 0; i <= n; ++i){
            for(int j = i; j; (j >>= 1)){
                ans[i] += (j & 1);
            }
        } 
        return ans;
    }
};