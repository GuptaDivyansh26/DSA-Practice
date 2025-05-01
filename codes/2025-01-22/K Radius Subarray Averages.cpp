// K Radius Subarray Averages

// Initialised an array of size 'n' with -1. If n < k, no possible window, therefore return. Otherwise, firstly constant sum of window. Then
// add next element to the sum and remove first of window from the sum. Find avg, update value of resultant array and return it.

// TC- O(n) [Max- O(2*n)- one for high, another for i]
// SC- O(n) [array of size n for returning the answer]

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> res(n, -1);
        
        if(n < 2*k+1)
        {
            vector<int> ans(res.begin(), res.end());
            return ans;
        }
        else if(n == 1){
            res[0] = nums[0];
            vector<int> ans(res.begin(), res.end());
            return ans;

        }

        long long sum = 0;
        int low = 0, high = 0;

        for(high; high < k; high++)
        {
            sum += nums[high];
        }

        for(int i = 0; i < n; i++)
        {
            if(i - k < 0)
            {
                sum += nums[high];
                high++;
            }
            else if(i + k >= n)
            {
                break;
            }
            else
            {
                sum += nums[high];
                res[i] = sum / (2*k+1);
                high ++ ;

                sum -= nums[low];
                low ++;
            }
        }

        vector<int> ans(res.begin(), res.end());
        return ans;
    }
};