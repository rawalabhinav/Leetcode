#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve(vector<vector<int>>& grid, int k){
    int n = grid.size(), m = grid[0].size();

    vector <vector <vector <int>>> vis(n, vector <vector <int>> (m, vector <int>(k + 1)));

    queue <tuple <int, int, int>> q;

    q.push({0, 0, k});
    for(int len = q.size(), steps = 0; !q.empty(); --len){
        if (len == 0){
            ++steps;
            len = q.size();
        }

        auto [i, j, rem] = q.front();

        q.pop();
        rem -= grid[i][j];
        
        if (rem < 0 or vis[i][j][rem]) continue;

        // Important to prune
        if (i == n - 1 && j == m - 1) return steps;

        vis[i][j][rem] = true; 
        for(int x, y, z = 0; z < 4; ++z){
            x = i + dx[z], y = j + dy[z];

            if (x < 0 or x == n or y < 0 or y == m) continue;
            q.push({x, y, rem});
        }
    }

    return -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {0 , 0, 0}, {1, 1, 0}, {0, 0, 0},
        {0, 1, 1}, {0, 0 , 0}
    };

    cout  << solve(grid, 1);
}