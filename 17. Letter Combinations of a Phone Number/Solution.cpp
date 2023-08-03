#include <bits/stdc++.h>
using namespace std;

#ifdef RAWAL
    #include <Collections/debug.h>
#endif

#define int long long int

vector <string> ans;
string s, build;

const vector <vector <char>> m = {
    {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
    {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
};

void solution(int i = 0){
    if (i == s.length()){
        ans.emplace_back(build);
        return;
    }

    for(auto& e: m[s[i] - '2']){
        build[i] = e;
        solution(i + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> s; build = s;
    solution();

    debug(ans)
}