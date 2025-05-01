// Generating all Subarrays

class Solution {
  public:
    vector<vector<int> > getSubArrays(vector<int>& arr) {
        
        vector<vector<int>> res;
        
        for(int idx = 0; idx < arr.size(); idx++)
        {
            vector<int> temp = {};
            
            for(int jdx = idx; jdx < arr.size(); jdx++)
            {
                temp.push_back(arr[jdx]);
                
                res.push_back(temp);
            }
        }
        
        return res;
    }
};