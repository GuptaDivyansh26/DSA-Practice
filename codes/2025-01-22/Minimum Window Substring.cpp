// Minimum Window Substring

// Created hash array using string 't'. We increased size of window unitl all elements of 't' are found.
// Then, moved left to check for minimum windowSize. Repeated it until high >= n;

// TC- O(2*n) + O(m) [Traversal of high and low to the end + insertion in hash array]
// SC- O(256) [Hash Array for all 256 characters possible]

class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size();

        // unordered_map<char, int> mpp;
        array<int, 256> hash;
        for(auto it : t)
        {
            // mpp[it++];
            hash[it - 0]++;
        }

        int minn = INT_MAX, startingIdx = -1;
        int cntDistinct = 0;

        int low = 0, high = 0;

        while(high < n)
        {
            // if(mpp[s[high]] > 0)
            if(hash[s[high] - 0] > 0)
            {
                cntDistinct++;
            }
            // mpp[s[high]]--;
            hash[s[high] - 0]--;

            while(cntDistinct == m)
            {
                if(high - low + 1 < minn)
                {
                    startingIdx = low;
                    minn = high - low + 1;
                    // minn = min(minn, high - low + 1);
                }
                
                // mpp[s[low]]++;
                hash[s[low] - 0]++;

                // if(mpp[s[low]] > 0)
                if(hash[s[low++] - 0] > 0)
                {
                    cntDistinct--;
                }
            }

            high++;
        }

        return (startingIdx == -1) ? "" : s.substr(startingIdx, minn);
    }
};