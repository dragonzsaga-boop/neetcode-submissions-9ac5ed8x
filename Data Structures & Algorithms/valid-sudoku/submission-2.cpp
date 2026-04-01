class Solution {
    bool validate(const vector<vector<char>>& board, 
                        int cr, int cc, int mr, int mc, int maxVal = 9) {
        vector<bool> bv(maxVal, false);
        for(int i = cr; i < mr; ++i) {
            for(int j = cc; j < mc; ++j) {
                if(board[i][j] == '.') continue;
                
                if(bv[board[i][j]]) {
                    return false;
                }
                bv[board[i][j]] = true;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        for(int i = 0; i < board.size(); ++i) {
            if( !validate(board, i, 0, i+1, board[i].size()) )
                return false;
        }
        //check cols
        for(int j = 0; j < board[0].size(); ++j) {
            if( !validate(board, 0, j, board.size(), j+1) )
                return false;
        }
        //check grids
        for(int i = 0; i < board.size(); i+=3) {
            for(int j = 0; j < board[0].size(); j+=3) {
                if( !validate(board, i, j, i+3, j+3) )
                    return false;
            }
        }
        return true;
    }
};


// [".",".","4"][".",".","."]["6","3","."],
// [".",".","."][".",".","."][".",".","."],
// ["5",".","."][".",".","."][".","9","."],

// [".",".","."]["5","6","."][".",".","."],
// ["4",".","3"][".",".","."][".",".","1"],
// [".",".","."]["7",".","."][".",".","."],

// [".",".","."]["5",".","."][".",".","."],
// [".",".","."][".",".","."][".",".","."],
// [".",".","."][".",".","."][".",".","."]
