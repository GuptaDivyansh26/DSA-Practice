// Allocate Minimum Pages

// TC- O(n + log (sum of pages - max pages in  single book) * n)   [finding range + binary search * arr.length]
// SC- O(1) [No extra space used]
class Solution{
public:
    int findPages(vector<int> &arr, int k) {
    
        if(k > arr.size())  return -1;
        // Not enough books for every person
        
        int low =0, high =0;
        for(auto it: arr)
        {
            low = max(low, it);
            high += it;
        }
        // Min no of pages that can be allotted is the maximum available
        // in a single book. Max no of pages is sum of all pages from all books
        // (if 1 person takes all books).
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // Maximum no of pages assigned to student
            
            long long sum = 0;
            int cnt = 0;
            // cnt is no. of students who recieved books
            for(int i= 0; i < arr.size(); i++)
            {
                if(sum + arr[i] > mid)
                {
                    cnt++;
                    sum = arr[i];
                }
                else    sum += arr[i];
            }
            
            if(sum <= mid)  cnt++;
            
            if(cnt <= k) high = mid - 1;
            else    low = mid + 1;
            // If no of students recieving books is less or equal to k, each
            // student must get less pages then. Else, more.
        }
        
        return low;
    }
};