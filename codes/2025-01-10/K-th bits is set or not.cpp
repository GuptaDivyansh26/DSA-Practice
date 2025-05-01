// K-th Bit is Set or Not
// TC- O(1) + O(1)
// SC- O(1) [No extra space]

// Anding with (000...010...000).   If Kth bit is zero, answer will be 0. Else any other number (000...010...000).

class solution {    
    public:
        bool checkKthBit(int n, int k)
        {
            int x = 1;
            
            x = x << k ;
            
            if((n & x) == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
};