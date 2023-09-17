#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.emplace_back(0);

        int n = h.size(), ans = 0;
        stack <pair<int, int>> s;

        for(int j = 0; j < n; ++j){
            int left = 0;

            while(!s.empty() && h[j] <= h[s.top().first]){
                auto [i, l] = s.top();

                ans = max(ans, (j - i + l) * h[i]);
                left += l + 1;
                s.pop();
            }

            s.push({j, left});
        }

        return ans;
        
    }
};