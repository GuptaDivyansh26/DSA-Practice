// Generat All Binary Strings

// Approach - 1 : Using a temp string to store result and push it back to final vector
// TC- O(2 ^ N) [Pick/Non-Pick; Choosing both 0/1; skipping 1 if last is 1]
// SC- O(N) [temp vector]

class Solution{
public:
    void BS(int idx, int& n, string temp, vector<string>& ans)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        
        BS(idx + 1, n, temp + '0', ans);
        
        if(temp.back() != '1')  BS(idx + 1, n, temp + '1', ans);
    }

    vector<string> generateBinaryStrings(int num){
        
        vector<string> ans;
        string temp = "";
        
        BS(0, num, temp, ans);
        
        return ans;
    }
};

// Approach - 2 : Directly putting answers into final vector w/o using temp string.
// TC- O(N ^ 2)	[for loop, N times]
// SC- O(N) [Recursion Space]

class Solution{
public:
    vector<string> generateBinaryStrings(int n)
    {        
        if(0 == n)
        {
            return {""};
        }
        
        vector<string> prevOut = generateBinaryStrings(n - 1);
        vector<string> result = {};
        
        for(string& str: prevOut)
        {
            str.push_back('0');
            result.push_back(str);
            str.pop_back();
            
            if(str.back() != '1')
            {
                str.push_back('1');
                result.push_back(str);
                str.pop_back();
            }
        }
        
        return result;
    }
};