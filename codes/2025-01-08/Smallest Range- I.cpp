// Smallest Range- I

// Since x can be varied b/w [-k, k], min difference = highest-k  -  lowest+k;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k)
    {
        int high = *max_element(nums.begin(), nums.end()) ;
        int low = *min_element(nums.begin(), nums.end()) ;
        
        return max(0, high - low - 2*k) ;  
    }
};