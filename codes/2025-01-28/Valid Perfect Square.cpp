// Valid Perfect Square

// Mid nikal kr uska square check krte jaayenge..If greater than num, high update kr denge..else, low update kr denge.
// At any point, if mid^2= num, return true, else return false;

// TC- O(log n with base 2) [Eliminating half search space with each iteration]
// SC- O(1) [No extra space needed except for the inbuilt function (isBadVersion)]

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int low = 1, high = num;

        while(low <= high)
        {
            long int mid = low + (high - low) / 2;

            if((mid * mid) > num) high = mid - 1;
            else if((mid * mid) < num) low = mid + 1;
            else    return true;
        }

        return false;
    }
};