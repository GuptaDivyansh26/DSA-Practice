// Sudoku Solver

// We'll find the sudoku for an empty cell. Try all valid choices from 1-9 and we'll move on to the next empty block. If no more, empty box remains, we return true.
// If we find an empty box with no possible valid choice from 1-9, it means previous selection was wrong, and we return false.

// TC - O(pow(9, pow(n, 2))) [For each block in N^2, we have 9 choices]
// SC - O(N^2) [Recursion Stack Space]

// My soln. with a little lengthy isValid function but easy iteration on sudoku
class Solution {
public:
    bool checkrow(char val, vector<vector<char>>& board, int& i, int& j)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == val)  return false;
        }

        return true;
    }
    bool checkcol(char val, vector<vector<char>>& board, int i, int j)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][j] == val)  return false;
        }

        return true;
    }
    bool checkbox(char val, vector<vector<char>>& board, int row, int col)
    {
        for(int idx = 3 * (row / 3); idx < (3 * (row / 3)) + 3; idx ++)
        {
            for(int jdx = 3 * (col / 3); jdx < (3 * (col / 3)) + 3; jdx ++)
            {
                if(board[idx][jdx] == val)  return false;
            }
        }

        return true;
    }
    bool isValid(char val, vector<vector<char>>& board, int i, int j)
    {
        return 
            checkrow(val,board,i,j) &&
            checkcol(val,board,i,j) &&
            checkbox(val,board,i,j);
    }
    bool solve(vector<vector<char>>& board, int idx)
    {
        for(int i = idx; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isValid(c, board, i, j))
                        {
                            board[i][j] = c;
                            
                            if(solve(board, i))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
};

// Improving isValid function with Striver's help
class Solution {
public:
    bool isValid(char val, vector<vector<char>>& board, int row, int col)
    {
        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == val)  return false;

            if(board[row][i] == val)  return false;

            if(board[3* (row / 3) + i / 3][3*(col / 3) + i % 3] == val)   return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int idx)
    {
        for(int i = idx; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isValid(c, board, i, j))
                        {
                            board[i][j] = c;
                            
                            if(solve(board, i))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
};