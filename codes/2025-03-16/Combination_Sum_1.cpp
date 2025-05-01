// Combination Sum - 1

// Same as subsets with equal sum. Just one element is allowed multiple time. Hence, one time we'll repeat it. Once we'll move to next.

// TC- 2^t * k --> k is avg legth of every possible combination generated, *k as we are putting it in res i.e. exponential
// SC- k * x --> x is no. of combinations. Here, we do not consider auxillary space.

class Solution {
public:
    void func(int idx, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res)
    {
        if(idx >= arr.size())
        {
            if(target == 0)
            {
                res.push_back(temp);
            }
                
            return;
        }

        if(target - arr[idx] < 0 || target == 0)   goto label;

        temp.push_back(arr[idx]);
        func(idx, target - arr[idx], arr, temp, res);

        temp.erase(temp.end() - 1);

        label:
        func(idx + 1, target, arr, temp, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;

        vector<int> temp;

        func(0, target, candidates, temp, res);

        return res;

    }
};