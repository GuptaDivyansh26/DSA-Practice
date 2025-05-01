// Capacity to Ship Packages

// TC- O(n) + O(n log (b - a)) where n --> size of array 'weights', a --> max element in array, b --> sum of all elements of array
// SC- O(1) [No extra space used]

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Basically minimum of maximum wt. capacities nikaalni h. Maximum wt. arr[max] se start hoga (kyunki usse kam hua toh vo wala nhi jaa paayega) and sum pe end hoga(saare ek saath bhej skte h)

        int low = 0, high = 0;
        for(auto it : weights)
        {
            low = max(low, it);
            high += it;
        }

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // mid is max wt. capacity

            int sum = 0, count = 0;
            // count is no. of days for given scenario
            for(auto it : weights)
            {
                if(sum + it > mid){

                    count++;
                    sum = it;
                }
                else{

                    sum += it;
                }        
            }
            if(sum != 0)    count++;

            if(count <= days)   high = mid - 1;
            else    low = mid +1;
        }

        return low;
    }
};