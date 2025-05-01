// Search insert position

// We'll keep reducing the search step and apply following conditions to find the insert position
// It cannot be null or -1, it can range from 0 to nums.end();

// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [No extra space required]

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int idx = -1;
        int low = 0, high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                idx = mid;
                high = mid - 1;                
            }
            else
            {
                idx = mid + 1;
                low = mid + 1;
            }
        }

        return idx;
    }
};