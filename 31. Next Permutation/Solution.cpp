#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> & nums) {
        int n = nums.size();

        for(int i = n - 2; i > - 1; --i){
            if (nums[i] < nums[i + 1]){
                reverse(nums.begin() + i + 1, nums.end());

                for(int j = i + 1; j < n; ++j){
                    if (nums[j] > nums[i]){
                        swap(nums[i], nums[j]); return;
                    }
                }
            }
        }

        reverse(nums.begin(), nums.end());
    }
};