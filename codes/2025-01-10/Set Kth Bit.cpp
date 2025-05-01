// Set Kth Bit
// TC- O(1) + O(1)
// SC- O(1) [No extra space]

class solution {    
    public:
        int setKthBit(int n, int k)
        {
            int x = 1;
            
            x <<= k;
            
            return n | x ;
        }
};