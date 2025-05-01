// Count Set bits

// 3 approaches

// 1. Loop until length
// TC- O(n)     n--> No. of bits to repsnt. 'n' in binary format. (i.e. 32)
// SC- O(1) [No extra space]

// ANDing with 1 to check the digit. FInally, right shift to move to next digit.


class solution {    
    public:
        int setBits(int n)
        {
            int cpy = n;
            int count = 0;
            
            while(cpy != 0){
                
                if((cpy & 1) == 1)  count++;
                cpy = cpy >> 1;
            }
            
            return count ;
        }
};

// 2. Kernighan's Algorithm
// TC- O(n)     n--> no. of set bits in given number
// SC- O(1) [No extra space]

// n-1 differs from n in binary repst. upto first set bit occurence, rest all remains same. Hence,ANDing results in rest same followed by 0s.

class solution {    
    public:
        int setBits(int n)
        {
            int ans = 0 ;
            
            while(n)
            {
                ans++;
                n = n & (n - 1) ;
            }
            
            return ans ;
        }
};

// 3. STL
// TC- O(1)
// SC- O(1) [No extra space]

// __builtin_popcount(int n)--> This inbuilt function is used to count the number of set bits in an unsigned integer.

class solution {    
    public:
        int setBits(int n)
        {
            return __builtin_popcount(int n) ;
        }
};