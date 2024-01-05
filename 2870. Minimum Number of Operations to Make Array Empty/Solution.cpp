#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& a) {
        int ans = 0, n = a.size();

        unordered_map <int, int> m;
        for(int& e: a) ++m[e];

        int k, v;
        for(auto& p: m){
            tie(k, v) = p;

            if (v == 1) return -1;
            ans += v / 3 + bool(v % 3);
        }

        return ans;
    }
};