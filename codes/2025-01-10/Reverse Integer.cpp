// Reverse Integer
// TC- O(1)
// SC- O(1) 

// Not properly clear. Hence, no explaintion


class Solution {
public:
    int reverse(int x) {
        
        int minn = INT_MIN ;
        int maxx = INT_MAX ;

        int rev = 0;

        while(x !=0)
        {
            int rem = x % 10;

            if(rev > maxx/10 || rev < minn/10) return 0 ;

            rev = rev * 10 + rem ;

            x = x / 10;
        }

        return rev;
    }
};