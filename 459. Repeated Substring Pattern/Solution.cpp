#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int i = 1; i < n; ++i){
            if (n % i) continue;
            int repeated = true;

            for(int j = 0; j < n; j += i){
                for(int k = j, l = 0; k < j + i; ++k, ++l){
                    if (s[k] != s[l]){
                        repeated = false;
                        j = n;
                        break;
                    }
                }
            }

            if (repeated) return true;
        }

        return false;
    }
};