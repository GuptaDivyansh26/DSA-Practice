// Find Pivot Index

// Brute- Loop from 0 to size to calculate left and right sum
// TC- O(N^2)
// SC- O(1) [No extra space used]

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            int leftSum = 0, rightSum= 0;

            for(int jdx = 0; jdx < idx; jdx++)
            {
                leftSum += nums[jdx];
            }

            for(int jdx = idx + 1; jdx < nums.size(); jdx++)
            {
                rightSum += nums[jdx];
            }

            if(leftSum == rightSum) return idx;
        }

        return -1;
    }
};



// Better- STL
// TC- O(N)
// SC- O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int leftSum = 0;
        
        int total = accumulate(nums.begin(), nums.end(), 0);

        for(int idx = 0; idx < nums.size(); idx++)
        {
            int rightSum = total - nums[idx] - leftSum;
            
            if(leftSum == rightSum) return idx;
            
            leftSum += nums[idx];
        }
        
        return -1;
    }
};



// No idea..dimaag mein aaya, code kiya, chal gya..dk TC or SC
// TC- 
// SC- 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        multimap<int, int> mpp1;
        multimap<int, int> mpp2;

        mpp1.insert({0, 0});
        mpp2.insert({0, nums.size() - 1});

        int leftSum = 0, rightSum= 0;

        for(int idx = 1; idx < nums.size(); idx++)
        {
            leftSum += nums[idx -1];
            mpp1.insert({leftSum, idx});

            rightSum += nums[nums.size() - idx];  
            mpp2.insert({rightSum, nums.size() - idx - 1}); 
        }

        for(auto it1 : mpp1)
        {
            for(auto it2 : mpp2)
            {
                if((it1.first == it2.first) && (it1.second == it2.second))
                {
                    return it1.second;
                }
            }
        }
        
        return -1;
    }
};