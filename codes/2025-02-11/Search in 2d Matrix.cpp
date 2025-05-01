// Search in a 2D matrix

// Brute- Traverse every element of matrix to search for target

// TC- O(n*m) --> n = no. of rows, m = no. of columns
// SC- O(1) [No extra space used]


// Better- Apply binary search on each row to find the target

// TC- O(n * log m) --> n = no. of rows, m = no. of columns
// SC- O(1) [No extra space used]


// Optimised- Apply binary search on first element of each row to identify possible row and then again apply binary search on columns of that
// particular row.

// TC- O(log (n*m)) --> n = no. of rows, m = no. of columns
// SC- O(1) [No extra space used]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(matrix[mid][0] > target) high = mid - 1;
            else    low = mid + 1;
        }

        if(high < 0)    return false;

        int low1= 0, high1 = m-1;
        while(low1 <= high1)
        {
            int mid = (low1 + high1) / 2;

            if(matrix[high][mid] == target)  return true;
            else if(matrix[high][mid] > target)  high1 = mid - 1;
            else  low1 = mid + 1;
        }

        return false;
    }
};