#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            curFarthest = max(curFarthest, i + a[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};