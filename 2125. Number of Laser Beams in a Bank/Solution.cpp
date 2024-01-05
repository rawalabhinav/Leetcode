#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int n = a.size(), m = a[0].size();

        int ans = 0, cur = 0, prev = 0;
        for(int i = 0; i < n; ++i){
            for(char& c: a[i]){
                cur += (c == '1');
            }

            ans += cur * prev;
            if (cur) {
                prev = cur;
                cur = 0;
            }
        }

        return ans;
    }
};