// Range Sum Query

// Brute - For loop for every l and R
// TC- O(N) --> N = R - L + 1
// SC- O(1) [No extra space for solving the problem, one array to be taken to store nums]

class NumArray {
    vector<int> temp;
public:
    NumArray(vector<int>& nums) {
        
        for(auto it : nums)
        {
            temp.push_back(it);
        }
    }
    
    int sumRange(int left, int right) {
        
        int sum = 0;

        for(int idx = left; idx <= right; idx++)
        {
            sum += temp[idx];
        }

        return sum;
    }
};



// Better - Pre-traversal
// Jab multiple cases run krne ho in same object with varying range, try bringing it down from o(N) to o(1) by making prefix array.
// O(N) toh lgega hi for prefix, but test cases mein constant time aa jaayega

// TC- O(1) [Loop is to be traversed once, but uske baad constant time]
// SC- O(N+1) = O(N) [Prefix sum ke liye array]

class NumArray {    
public:

    vector<int> prefix = {0};

    NumArray(vector<int>& nums) {

        int sum = 0;

        for(int idx = 0; idx < temp.size(); idx++)
        {            
            sum += temp[idx];
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        
        int sum = 0;
        
        return prefix[right + 1] - prefix[left];
    }
};