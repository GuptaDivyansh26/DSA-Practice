// K-th Missing Positive Number

// Using binary search to find range of elements where the missing number will lie. After, subtracting lower bound of range from 'k' to find
// no. of missing numbers required. Adding that to the value of lowerbound will give us the missing number.

// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [No extra space needed]

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int low = 0, high = arr.size() - 1;

        if(arr[0] > k)  return k;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(arr[mid] - mid - 1 < k)
            {
                low = mid + 1 ;
            }
            else
            {
                high = mid - 1;
            }
        }

        int res = arr[high] + (k - (arr[high] - high - 1));

        return res;
    }
};