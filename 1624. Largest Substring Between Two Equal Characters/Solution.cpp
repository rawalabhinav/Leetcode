#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ind[26]{};
        int ans = -1;

        for(int i = 0; i < s.length(); ++i){
            if (ind[s[i] - 'a']) ans = max(ans, i - ind[s[i] - 'a']); 
            else ind[s[i] - 'a'] = i + 1;
        }

        return ans;
    }
};