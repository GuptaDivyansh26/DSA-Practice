// Koko eating Bananas

// TC- O(n log (*max_element(piles.begin(), piles.end()))) where n --> size of array 'piles'
// SC- O(1) [No extra space used]

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = *max_element(piles.begin(), piles.end());
        // Atleast 1 hr, Atmost the max element as she can eat all that in 1 hr.

        while(low <= high)
        {
            // mid is the no. of kelas coco eats in an hour
            int mid = low + (high - low) / 2;

            // ans is variable used to store no. of hours it took to eat 'mid' kelas
            long long ans = 0;
            for(auto it: piles)
            {
                ans += (int)(ceil(((double)it)/mid));
            }
            // it/mid returns int, therefore ceil would never work. Hence, converting it to double first

            if(ans <= h) high = mid - 1;    //No of kelas decreased since we have time remaining
            else    low = mid + 1;  //No of kelas increased since crossing time limit
        }

        return low;
    }
};