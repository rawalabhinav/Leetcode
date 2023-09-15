#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        
        int far = 0;
        for(int i = 0; i < n; ++i){
            if (i > far) return false;
            if (i + a[i] > far) far = i + a[i];
        }

        return true;
    }
};