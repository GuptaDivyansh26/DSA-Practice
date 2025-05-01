// Floor in Sorted Array

// Using loop- Until high >= low, reducing search space with each step. (Baaki explain krne jaisa kuch h nhi brother ismein, kya bolu smjh nhi aa rha)
// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [No extra space required]

class Solution {
public:
    int findFloor(vector<int>& arr, int k)
    {
        int idx = -1;
        int low = 0, high = arr.size() -1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if(arr[mid] == k)
            {
                idx = mid;
                return mid;
            }
            else if(arr[mid] > k)
            {
                high = mid - 1;
            }
            else
            {
                idx = mid;
                low = mid + 1;
            }
        }
        
        return idx;
    }
};