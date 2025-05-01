// Combination Sum - 3

// Concept of pick / non-pick is used. If base condition satisfies, temp arry added to resultant array.

// TC- 2^9 * 3 --> 9 is no. of unique elements; 3 is length of every possible combination generated, *k as we are putting it in res
// SC- 3 * x --> x is no. of combinations. Here, we do not consider auxillary space.

class Solution {
public:

    void func(int k, int n, vector<vector<int>> &ans, vector<int> &t, int i = 1, int sum = 0)
    {
        if (t.size() == k && sum == n)
        {
            ans.push_back(t);
            return;
        }
        if (i > 9)
        {
            return;
        }
        
        t.push_back(i);
        func(k, n, ans, t, i + 1, sum + i);

        t.pop_back();
        func(k, n, ans, t, i + 1, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {        
        vector<vector<int>> res;
        vector<int> temp;

        func(k, n, res, temp);

        return res;
    }
};