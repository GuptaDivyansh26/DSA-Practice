// Subarray Sum Equals K

// Brute - 3 loops
// TC- O(N^3)
// SC- O(1) [No extra space]

class Solution {
public:

    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int cnt = 0; 
    
        for (int idx = 0 ; idx < n; idx++)
        { 
            for (int jdx = idx; jdx < n; jdx++)
            {
                int sum = 0;
                
                for (int kdx = idx; kdx <= jdx; kdx++)
                {
                    sum += nums[kdx];
                }
    
                if (sum == kdx)   cnt++;
            }
        }
        
        return cnt;
    }
};



// Better - 2 loops
// TC- O(N^2)
// SC- O(1) [No extra space]

class Solution {
public:

    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
    
        for (int idx = 0 ; idx < n; idx++)
        {
            int sum = 0;
            
            for (int jdx = idx; jdx < n; jdx++)
            { 
                sum += nums[jdx];
    
                if (sum == kdx)   cnt++;
            }
        }
        
        return cnt;
    }
};



// Optimised - Using Pre-Sum
// TC- O(N) for unordered map --> N = nums.size()
// SC- O(N) [Unordered map data structure]

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> mpp;
        
        mpp[0] = 1;
        
        int ans = 0;
        int count = 0;
        
        for(int idx = 0; idx < nums.size(); idx++){

            count += nums[idx];
            ans += mpp[count - k];
            mpp[count]++;
            
        }

        return ans;
    }
};