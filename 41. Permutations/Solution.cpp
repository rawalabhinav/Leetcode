#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector <int> tmp;

    void f(int i, int mask, vector <int>& a){
        if (i > n - 1){
           ans.push_back(tmp);
           return;
        }

        for(int k = 0; k < n; ++k){
            if (mask & (1 << k)){
                tmp[i] = a[k];
                f(i + 1, mask ^ (1 << k), a);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& a)  {
        n = a.size();
        tmp.resize(n, n +);

        f(0, (1 << n) - 1, a);

        return ans;
    }
};