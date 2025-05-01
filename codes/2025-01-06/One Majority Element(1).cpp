// One majority element (> N/2)

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int maxVar = -1 ;
        
        int votes = 0 ;
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            if(nums[idx] == maxVar)
            {
                votes ++ ;
            }
            else
            {
                if(votes > 0)
                {
                    votes -- ;
                }
                else if(votes == 0)
                {
                    maxVar = nums[idx] ;
                    votes ++ ;
                }
            }
        }
        
        int count = 0 ;
        
        for(auto it : nums)
        {
            if(it == maxVar)    count++ ;
        }

        return maxVar ;
    }
};