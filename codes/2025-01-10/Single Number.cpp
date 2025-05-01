// Single Number

// XOR of all numbers
// TC- O(n)
// SC- O(1) [No extra space]

// This is optimal approach for given question but only approach using bit manulpulation.
// a ^ a = 0
// 0 ^ a = a


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = 0;

        for(int idx = 0; idx < nums.size(); idx++)
        {
            n ^= nums[idx];
        }

        return n;
    }
};