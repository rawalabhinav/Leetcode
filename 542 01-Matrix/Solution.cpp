#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int dx[4] = {1, 0, -1, 0};
    static constexpr int dy[4] = {0, -1, 0, 1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        queue <pair<int, int>> q;

        vector <vector <int>> d(n, vector <int>(m, m + n));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if (!a[i][j]){
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }

        for(; !q.empty();  q.pop()){
            auto [i, j] = q.front();

            for(int k = 0; k < 4; ++k){
                int x = i + dx[k], y = j + dy[k];

                if (x < 0 or x == n or y < 0 or y == m or d[x][y] <= 1 + d[i][j]){
                    continue;
                }

                q.push({x, y});
                d[x][y] = 1 + d[i][j];
            }
        }

        return d;
    }
};