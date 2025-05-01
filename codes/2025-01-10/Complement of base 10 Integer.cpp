// Complement of base 10 integer

// 4 approaches- All of them are based on same idea, i.e.e a ^ ~a = 111...111 (n times). --> 111...111 ^ a = ~a.

// 1. Loop until length
// TC- O(1)
// SC- O(1) 

// loop to count digits in 'n'. Then left shift to create number of format "111...111".


class Solution {
public:
    int bitwiseComplement(int n)
    {
        int len = 1;
        
        int cpy = n;
        
        while(cpy != 0 && cpy != 1)
        {
            cpy >>= 1;
            len = len + 1;
        }
        
        int helper = 0;
        helper = (1 << len) - 1;

        return helper ^ n;

    }
};

// 2. Using logarithmic function
// TC- O(1)  
// SC- O(1)

// log func to count digits in 'n'. Then left shift to create number of format "111...111".

class Solution {
public:
    int bitwiseComplement(int n)
    {
        int len;
        n  == 0 ? len = 1 : len = ((int) log2(n)) + 1;
        
        int helper = 0;
        helper = (1 << len) - 1;

        return helper ^ n;

    }
};

// 3. STL
// TC- O(1)
// SC- O(1) 

// __builtin_clz(int n)--> This inbuilt function is used to count the number of leading zeroes in an unsigned integer.

class Solution {
public:
    int bitwiseComplement(int n)
    {
        if(n == 0)  return 1;

        int len = 32 - __builtin_clz(n);
        
        int helper = 0;
        helper = (1 << len) - 1;

        return helper ^ n;

    }
};

// 4. Forming helper using 'n'
// TC- O(1)
// SC- O(1) 

// let 100...000.  Making it 110..000.  Then 11110..000. And doon, until 111...111.

class Solution {
public:
    int bitwiseComplement(int n)
    {   
        if(n == 0)  return 1;
             
        int helper = n;

        helper = helper | (helper >> 1);
        helper = helper | (helper >> 2);
        helper = helper | (helper >> 4);
        helper = helper | (helper >> 8);
        helper = helper | (helper >> 16);

        return helper ^ n;

    }
};