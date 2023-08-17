#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        // can be done without set using pq of pair (val, index);
        multiset <int> s(a.begin(), a.begin() + k);
        vector <int> ans;
        a.emplace_back(0);

        for(int i = k; i <= n; ++i){
            ans.emplace_back(*s.rbegin());

            s.erase(s.find(a[i - k]));
            s.insert(a[i]);
        }

        return ans;
    }
};