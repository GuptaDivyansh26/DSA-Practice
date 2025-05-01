// Sliding Window Maximum

// We'll take first k elements and insert them into multiset. Since set, elements sorted. Last element maximum. Add nums.next to set and 
// erase nums.low from set. Repeat until high < n;

// TC- O(n * log n) [In a multiset, insertion, deletion or finding takes log n time.]
// SC- O(k) [k -> window size]

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int> st;
        vector<int> ans;

        int lo = 0;
        int hi = k - 1;

        for(int i = 0; i <= hi; i++)
        {
            st.insert(nums[i]);
        }

        ans.push_back(*prev(st.end()));

        for(int i = hi + 1; i < nums.size(); i++)
        {
            lo++;
            hi++;

            auto itr = st.find(nums[lo - 1]);
            st.erase(itr);

            st.insert(nums[hi]);

            ans.push_back(*prev(st.end()));
        }

        return ans;
    }
};