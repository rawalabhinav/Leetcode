#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimizeMax(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int l = 0, r = 1e9, m;

        auto possible = [&]() -> bool { 
            int pairs = 0;

            for(int i = 1; i < a.size(); ++i){
                if (a[i] - a[i - 1] > m) continue;
                ++i, ++pairs;
            }

            return pairs >= p;
        };

        for(m = (l + r) / 2; l < r; m = (l + r) / 2){
            possible() ? r = m : l = m + 1;
        }

        return l;
    }
};