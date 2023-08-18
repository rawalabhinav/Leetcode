#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edge) {
        vector <int> d(n);
        vector <vector <int>> adj(n, vector <int> (n));

        int ans = 0;
        for(auto& p: edge){
            int u = p[0], v = p[1];

            adj[u][v] = 1, adj[v][u] = 1;
            ++d[u], ++d[v];   
        }


        for(int i = 0; i < n; ++i){
            for(int j = i + 1;  j < n; ++j){
                ans = max(ans, d[i] + d[j] - adj[i][j]);
            }
        }

        return ans; 
    }
};