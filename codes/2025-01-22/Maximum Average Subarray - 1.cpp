// Maximum Average Subarray - I

// Initialised avg to INT_MIN. Run loop from 0 to k to find first window and windowSum. Update avg. Second loopfrom k to n adding new element
// and removing first of window at each step. Further, updating avg on each step. Finally, returned avg.

// TC- O(n) [Single traversal from 0 to k and then k to n]
// SC- O(1) [No extra space used]

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        double avg = INT_MIN;
        
        if(n == 1)
        {
            return nums[0];
        }

        double sum = 0;
        int low = 0, high = 0;

        for(high; high < k; high++)
        {
            sum += nums[high];
        }

        avg = max(avg, sum / k);

        for(high; high < n; high++)
        {
            sum += nums[high];
            sum -= nums[low];

            avg = max(avg, sum / k);

            low ++;
        }

        return avg;
    }
};