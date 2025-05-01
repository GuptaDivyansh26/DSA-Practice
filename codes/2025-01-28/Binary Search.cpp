// Binary search

// Using loop- Reducing our search space to half at each step.
// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [No extra space required]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                idx = mid;
                break;
            }
        }

        return idx;
    }
};

// Using recursion- Dividing array into two halves, repeating until one element left. Then returning value from bottom to top. Else, -1.
// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(n/2 + n/4 + n/8 + .... + 1) = O(n/2) [Extra space for passing the array to function]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] > target)
            {
                vector<int> arr(nums.begin(), nums.begin() + mid);
                return search(arr, target);
            }
            else if(nums[mid] < target)
            {
                vector<int> arr(nums.begin() + mid + 1, nums.end());
                return search(arr, target);
            }
            else
            {
                idx = mid;
                return idx;
            }
        }

        return -1;
    }
};