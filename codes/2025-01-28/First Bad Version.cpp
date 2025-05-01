// First Bad Version

// Mid check krte jaayenge..If bad, right part eliminate krke left mein mid nikalenge..else, left eliminate krke right part mein first occurence
// nikal ke return krwa denge

// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [No extra space needed except for the inbuilt function (isBadVersion)]

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 1, high = n;
        int idx = -1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(isBadVersion(mid))
            {
                idx = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return idx;
    }
};