// Unset Kth Bit
// TC- O(1) + O(1) + O(1)
// SC- O(1) [No extra space]

// x=1 (000...001). x <<= k (000..010..000).  x = ~x (111..101..111).  n & x = (original bits...0...original bits).

class solution {    
    public:
        int unsetKthBit(int n, int k)
        {
            int x = 1;
            
            x <<= k;
            
            x = ~(x) ;
            
            return n & x ;
        }
};