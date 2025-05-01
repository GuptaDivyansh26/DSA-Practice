// Maximum Subarray Sum

// Optimised Approach- Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int count = 0, maxi = INT_MIN;
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            count += nums[idx];
            
            maxi = max(maxi, count);
            
            if(count < 0)
            {
                count = 0;
            }
            
        }
        
        return maxi;
    }
};