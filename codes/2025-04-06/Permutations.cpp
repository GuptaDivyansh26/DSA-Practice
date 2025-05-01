// Permutations

// Using extra space - We select an element, put it to our temp daa structure, mark it true (i.e. marked) in map. Next, we reiterate on array to see next non-picked element. Since "for" loop, we can choose every element for every position of permutation. When temp.size() = size of original array, we return.

// TC - O(N! * N) [n! permutations, looping on array of n for each permutation]
// SC - O(N) + O(N) ~ O(N) [vector temp + unordered map]

class Solution {
public:
    void Perm(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, unordered_map<int, bool>& mpp)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            
            return;
        }

        for(int idx = 0; idx < nums.size(); idx++)
        {
            if(mpp[idx] == false)
            {
                temp.push_back(nums[idx]);
                mpp[idx] = true;

                Perm(nums, temp, res, mpp);

                temp.pop_back();
                mpp[idx] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        unordered_map<int, bool> mpp;

        Perm(nums, temp, res, mpp);

        return res;
    }
};

// W/O using extra space - Swap all the elements one by one with element at 0 index. Move the pointer to same index and repeat until pointer reaches size of nums. Once it does, return. Intuition is, instead of remembering whether we have picked an element or not, we are forcefully placing an element at a particular index.

// TC - O(N! * N) [n! permutations, looping on array of n for each permutation]
// SC - O(N) [Recusrsion stack space]

class Solution {
public:
    void Perm(int idx, vector<int>& nums, vector<vector<int>>& res)
    {
        if(idx >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        // Every number should be at a particular index
        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            Perm(idx + 1, nums, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;

        Perm(0, nums, res);

        return res;
    }
};