// Two majority element (> N/3)

class Solution {
public:
    vector <int> majorityElement(vector<int>& nums) 
    {        
        unordered_map <int, int> mpp ;
        
        vector <int> ans ;
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            mpp[nums[idx]] ++ ;
        }
        
        for(auto it : mpp)
        {
            if(it.second > nums.size() / 3)
            {
                ans.push_back(it.first) ;
            }
            
            if(ans.size() == 2) break ;
        }
        
        return ans ;
    }
};