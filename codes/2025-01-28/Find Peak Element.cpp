// Find Peak Element

// Mid nikal ke left aur right element check karo. 4 cases possible. Strictly increasing (then remove all left part),
// Strictly decreasing (then remove all right part), mid element greater than left and right (it's peak, return mid),
// else(peak on either sides, so low = mid + 1). Jaise hi peak mile, break;

// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [Constant Space taken by getLeft and getRight functions]

class Solution {
public:

    int getLeft(vector<int>& nums, int idx)
    {
        return idx == 0 ? INT_MIN : nums[idx - 1];
    }

    int getRight(vector<int>& nums, int idx)
    {
        return idx == nums.size() - 1 ? INT_MIN : nums[idx + 1];
    }

    int findPeakElement(vector<int>& nums) 
    {
        int low = 0, high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int left = getLeft(nums, mid);
            int right = getRight(nums, mid);

            if(nums[mid] > left && nums[mid] > right)
            {
                return mid;
            }
            else if(left < nums[mid] && nums[mid] < right)
            {
                low = mid + 1;
            }
            else if(left > nums[mid] && nums[mid] > right)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return 0;
    }
};