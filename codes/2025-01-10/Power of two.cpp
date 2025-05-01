// Power of Two
// TC- O(n)     n--> No of bits.
// SC- O(1) [No extra space]

// log of -ve & 0 is not possible. Right shifting to count no of bits ans then equating with answer to verify and compute result.


class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0)  return false;
        else
        {
            int count = 0 ;
            int cpy = n ;

            while(cpy != 0 && cpy != 1)
            {
                cpy = cpy >> 1;
                count++;
            }

            if(pow(2, count) == n)  return true;
            else return false;
        }
    }
};