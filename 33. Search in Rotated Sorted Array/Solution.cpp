#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        
        if (n == 1){
            return -1 + (a[0] == t); 
        }

        int l = 0, r = n - 1, m;
        for(m = (l + r) / 2; l < r; m = (l + r) / 2){
            if (a[m] == t) return m;

            // if m in second seg, r will converge to peak in 2nd seg only
            // if m in first seg, l will keep converging to index peak + 1
            a[m] < a[0] ?  r = m: l = m + 1;
        }

        auto it = lower_bound(a.begin() + l, a.end(), t);
        if (it != a.end() && *it == t) return it - a.begin();
        
        it = lower_bound(a.begin(), a.begin() + l, t);
        if (it != (a.begin() + l) && *it == t) return it - a.begin();

        return -1;
    }
};