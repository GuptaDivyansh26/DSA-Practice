// Subset Sum - 1

// We use a multiset to store duplicate valuesbut in a sorted order. Once, we add arr[dx] to sum, once we don't and call both of them recursively.

// TC- 2^n * n log n --> n is length of array [recursion * sorting]
// SC- 2^n [2^n possible values]

class Solution {
  public:
    void Sum(int idx, vector<int>& arr, multiset<int> &st, int sum)
    {
        // base condition
        if(idx >= arr.size())
        {
            st.insert(sum);

            return;
        }
        
        
        Sum(idx + 1, arr, st, sum);
        
        Sum(idx + 1, arr, st, sum + arr[idx]);
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        
        multiset<int> st;
        
        Sum(0, arr, st, 0);
        
        vector<int> res (st.begin(), st.end());
        return res;
    }
};