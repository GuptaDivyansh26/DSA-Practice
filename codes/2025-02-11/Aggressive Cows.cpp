// Aggressive cows

// TC- n log n + n log (max - min - 1)  [sorting + binary search * stalls.length]
// SC- O(1) [No extra space used]
class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());
        // sorting so that iteration becomes easy.
        
        int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
        // min. dist can be 1, and max can be last - first element of stalls
        int res = 0;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // min distance b/w wo stalls
            
            int last = stalls[0];
            // position of last stall
            
            int count = 1;
            // represents number of cows placed
            
            for(int idx = 1; idx < stalls.size(); idx ++)
            {
                if(stalls[idx] - last >= mid)
                {
                    count ++;
                    last = stalls[idx];
                }
            }
            // checks no of cows placed
            
            if(count >= k)
            {
                res = mid;
                low = mid + 1;
            }
            // if no of cows placed is equal or more, we can increase our distance
            else    high = mid - 1;
            // else, we need to decrease our distance
        }
        
        return res;
    }
};