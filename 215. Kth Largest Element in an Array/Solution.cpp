#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int n = a.size();

        multiset <int> m(a.begin(), a.begin() + k);
        for(int i = k; i < n; ++i){
            if (*m.begin() < a[i]){
                m.erase(m.begin());
                m.insert(a[i]);
            }
        }

        return *m.begin();
    }
};