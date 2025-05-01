// Generate Parenthesis

// Using a temp string to store result and push it back to final vector. We'll keep a count of left and right brackets and we'linsert only if they meet the criteria.

// TC- 2 * O(2 ^ N) [Pick/Non-Pick system for both left nd right brackets]
// SC- O(2*N) [temp vector for storing the answer]

class Solution {
public:
    void GP(int& n, string& temp, vector<string>& res, int cl, int cr)
    {
        if(temp.size() == 2*n)
        {
            res.push_back(temp);
            return;
        }

        if(cl >= n)  goto label;
        
        if(cl >= cr && cl != n)
        {
            temp.push_back('(');
            GP(n, temp, res, cl + 1, cr);
            temp.pop_back();
        }

        label:
        if(cl >= cr && cl != 0)
        {
            temp.push_back(')');
            GP(n, temp, res, cl, cr + 1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;

        string temp = "";

        GP(n, temp, res, 0, 0);

        return res;
    }
};