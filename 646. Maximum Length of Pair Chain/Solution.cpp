#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n = a.size();

        vector <int> p = a[0];
        int ans = 1;
        
        for(int i = 1; i < n; ++i){        
            if (a[i][1] > p[1]){
                
                if (p[1] >= a[i][0]) continue;
                p = a[i]; ++ans;
            }
            
            else p = a[i];
        } 

        return ans;       
    }
};