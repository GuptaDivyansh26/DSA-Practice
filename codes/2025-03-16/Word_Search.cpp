// Word Search

// we'll search first letter of word in m X n matrix. If not found, we'll return false; If found, we'll search its 4 adjacent directions to find second letter of the word.
// If found, we'll again call recursive function, hence return false. If we reach length of word during recursion, we'll return true and hence, the word is found.

// TC- m * n * 4 ^ k --> k is length of word. Worst case, we'll have to travel whole m X n  and 4 ^ k as 4 possible directions for every letter of word.
// SC- O(1) [No extra space used]

class Solution {
public:

    char checkTop(int i, int j, vector<vector<char>>& board){
        return i == 0 ? '0' : board[i - 1][j];
    }
    
    char checkLeft(int i, int j, vector<vector<char>>& board){
        return j == 0 ? '0' : board[i][j - 1];
    }
    
    char checkRight(int i, int j, vector<vector<char>>& board){
        return j == board[0].size() - 1 ? '0' : board[i][j + 1];
    }
    
    char checkBottom(int i, int j, vector<vector<char>>& board){
        return i == board.size() - 1 ? '0' : board[i + 1][j];
    }


    bool rec(int idx, int i, int j, vector<vector<char>>& board, string& word)
    {
        if(idx >= word.size())
        {
            return true;
        }

        bool a = false, b = false, c = false, d = false;

        if(checkTop(i, j, board) == word[idx])
        {
            board[i - 1][j] = '$';
            
            a = rec(idx + 1, i - 1, j, board, word);
            
            board[i - 1][j] = word[idx];
        }
        
        if(checkLeft(i, j, board) == word[idx])
        {
            board[i][j - 1] = '$';
            
            b = rec(idx + 1, i, j - 1, board, word);
            
            board[i][j - 1] = word[idx];
        }
        
        if(checkBottom(i, j, board) == word[idx])
        {
            board[i + 1][j] = '$';
            
            c = rec(idx + 1, i + 1, j, board, word);
            
            board[i + 1][j] = word[idx];
        }
        
        if(checkRight(i, j, board) == word[idx])
        {
            board[i][j + 1] = '$';
            
            d = rec(idx + 1, i, j + 1, board, word);
            
            board[i][j + 1] = word[idx];
        }

        return (((a || b) || c) || d);
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                bool d = false;
                
                if(board[i][j] == word[0])
                {
                    board[i][j] = '$';

                    d = rec(1, i, j, board, word);

                    if(d)   return true;

                    board[i][j] = word[0];
                }
            }
        }

        return false;
    }
};