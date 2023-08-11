#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

constexpr int mod = 1e9 + 7;

void solve() {
    int n, t; cin >> n >> t;

    vector <vector <int>> a(n, vector <int>(2));
    for(int i = 0; i < n; ++i){
        cin >> a[i][0] >> a[i][1];
    }

    vector <vector <int>> dp(n + 1, vector <int>(t + 1));
    dp[n][t] = 1;

    for(int i = n; i > 0; --i){
        for(int j = t; j > -1; --j){
            if (!dp[i][j]) continue;

            int cnt = a[i - 1][0];
            int marks = a[i - 1][1];

            // important k = [0 to cnt]
            for(int k = 0; k <= cnt; ++k){
                if (j - k * marks < 0) break;
                dp[i - 1][j - k * marks] += dp[i][j];
                dp[i - 1][j - k * marks] %= mod;
            }
        }
    } 

    cout <<  dp[0][0];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}