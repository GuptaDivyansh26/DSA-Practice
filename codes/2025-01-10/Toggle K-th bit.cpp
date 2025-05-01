// Toggling k-th bit of a number
// TC- O(1) + O(1)
// SC- O(1) [No extra space]

// XORing with (000...010...000).   If Kth bit is zero, answer will be 1. Else 0. For the rest bits--> XOR with 0. If they 0, ans 0. Else, 1.

class solution {    
    public:
        int checkKthBit(int n, int k)
        {
            int x = 1;
            
            x = x << k ;
            
            return n ^ x ;
        }
};