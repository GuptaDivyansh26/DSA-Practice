// First and Last position of element in Sorted Array

// TC- 2 * O(log n), n --> size of array nums
// SC- O(1) [No extra space used]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int fp = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // Returns first position of target (if exsts), else number greater to it
        int lp = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        // Returns number greater to it present in array

        if(fp == lp)
        {
            return {-1, -1} ;
        }
        // this means number doesn't existin array

        lp -- ;
        // to check last occurence of target

        return {fp, lp};
    }
};

// OR

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int fp = binarySearch(nums, target, true);
        int lp = binarySearch(nums, target, false);

        return {fp, lp};
    }

    // Binary Search function to find position
    int binarySearch(vector<int>& nums, int target, bool val)
    {
        int low = 0, high = nums.size() - 1, res = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                res = mid;

                if (val)    high = mid - 1;
                else    low = mid + 1;
            } 
            
            else if (nums[mid] < target)
            {
                low = mid + 1;
            } 
            
            else
            {
                high = mid - 1;
            }
        }

        return res;
    }
};