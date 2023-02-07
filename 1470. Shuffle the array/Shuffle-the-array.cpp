class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int f = 0, s = n, m = 1001;
        // s is pointer for y, f is for m  
        for(int i = 0; i < 2 * n; ++i){
            // nums[s++] is never updated in the traversal before i
            if((i & 1)) nums[i] = (nums[(s++)]) * m + nums[i];
            // % m helps remove the yj multiplier
            else nums[i] = (nums[(f++)] % m) * m + nums[i];
        }

        for(int i = 0; i < 2 * n; nums[i] /= m, ++i);
        return nums;
    }
};