#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& a, int s) {
        int n = a.size();

        vector <int> vis(n);
        queue <int> q; 

        for(q.push(s); !q.empty(); q.pop()){
            int u = q.front();

            if (a[u] == 0) return true;

            if (vis[u]) continue;
            vis[u] = 1;

            if (u + a[u] < n) q.push(u + a[u]);
            if (u - a[u] > -1) q.push(u - a[u]);
        }

        return false;
    }
};