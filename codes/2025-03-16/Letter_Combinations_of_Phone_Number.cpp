// Letter Combinations of a phone number

// we'll made a recursive function which checks the digit of the string. Acc. to the digit, it picks up the corresponding string and further calls itself for each value of that string.
// Repeated until all elements of string 'digits' are covered. Temp. string pushed into resultant vector whenever base condition meets.

// TC- digits.size() ^ 3 * k --> k is avg. time taken to put temp t resultant vector. Power 3 because on avg, every string has 3 characters.
// SC- (7 * 3 + 4) + (digits.size() ^ 3) + digits.size()  ~ O(25) [characters- Constant Space] [storing and returning the answer] [temp space]

class Solution {
public:

    string two = "abc";
    string three = "def";
    string four = "ghi";
    string five = "jkl";
    string six = "mno";
    string seven = "pqrs";
    string eight = "tuv";
    string nine = "wxyz";

    void combo(int idx, string& temp, string& digits, vector<string>& res)
    {
        if(idx >= digits.size())
        {
            res.push_back(temp);

            return;
        }

        if(digits[idx] == '2')
        {
            for(auto it : two)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '3')
        {
            for(auto it : three)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '4')
        {
            for(auto it : four)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '5')
        {
            for(auto it : five)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '6')
        {
            for(auto it : six)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '7')
        {
            for(auto it : seven)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '8')
        {
            for(auto it : eight)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
        else if(digits[idx] == '9')
        {
            for(auto it : nine)
            {
                temp += it;

                combo(idx + 1, temp, digits, res);

                temp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> res = {};

        string temp;

        if(digits.size() == 0)  return res;
        
        combo(0, temp, digits, res);

        return res;
    }
};