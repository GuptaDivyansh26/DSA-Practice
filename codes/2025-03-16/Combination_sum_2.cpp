// Combination Sum - 2

// Same as combination sum - 1. We'll add a parameter sum to keep count of sum of subarray and we'll add it to resultant v<v<i>> if sum == target.

// TC- 2^n * k --> n is no. of unique elementsk is avg legth of every possible combination generated, *k as we are putting it in res i.e. exponential
// SC- k * x --> x is no. of combinations. Here, we do not consider auxillary space.

class Solution {
public:

    void func(int idx, long long target, vector<int>& arr, vector<int> temp, vector<vector<int>>& res)
    {
        
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        

        for(int i = idx; i < arr.size(); i++)
        {
            if(i > idx && arr[i] == arr[i-1])   continue;
            if(arr[i] > target) break;

            temp.push_back(arr[i]);
            func(i+1, target - arr[i], arr, temp, res);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> temp;
        vector<vector<int>> res;

        long long t = target;

        sort(candidates.begin(), candidates.end());

        func(0, target, candidates, temp, res);

        return res;
    }
};