#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int sum) {
        string ans= "";
        for(int x = sum; x > 0; x = (x - 1) / 26){
            if (x % 26) ans = char('A' + x % 26 - 1) + ans;
            else ans = "Z" + ans;
        }
        
        return ans;
    }
};