#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string a) {
        // define the center and move your arms around ez
        int left = 0, right = 0;

        int n = a.length(), len = 1;
        for (int i = 0; i < n; ++i){
            for(int l = i - 1, r = i + 1; l >= 0 && r < n; ++r, --l){
                if (a[l] != a[r]) break;

                if (r - l + 1 > len) {
                    left = l, right = r;
                    len = r - l + 1;
                }
            }

            for(int l = i, r = i + 1; l >= 0 && r < n; ++r, --l){
                if (a[l] != a[r]) break;

                if (r - l + 1 > len) {
                    left = l, right = r;
                    len = r - l + 1;
                }
            }
        }

        return a.substr(left, len);
    }
};