#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int j = m - 2; j > -1; --j){
            grid[n - 1][j] += grid[n - 1][j + 1];
        }

        for(int i = n - 2; i > -1; --i){
            grid[i][m - 1] += grid[i + 1][m - 1];
        }

        for(int i = n - 2; i > -1; --i){
            for(int j = m - 2; j > -1; --j){
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }

        return grid[0][0];
    }
};