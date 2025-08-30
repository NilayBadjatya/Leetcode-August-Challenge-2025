class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        // Checking for each row values.
        for(int col = 0; col < n; col++){
            unordered_set<int> st;
            for(int row = 0; row < n; row++){
                if(board[row][col] == '.') continue;
                if(st.count(board[row][col]) != 0) return false;
                st.insert(board[row][col]);
            }
        }

        // Checking for each column values.
        for(int row = 0; row < n; row++){
            unordered_set<int> st;
            for(int col = 0; col < n; col++){
                if(board[row][col] == '.') continue;
                if(st.count(board[row][col]) != 0) return false;
                st.insert(board[row][col]);
            }
        }

        // Checking every 3x3 matrix
        for(int i = 0; i < n; i += 3){
            for(int j = 0; j < n; j += 3){
                unordered_set<int> st;
                for(int l = i; l < i+3; l++){
                    for(int k = j; k < j+3; k++){
                        if(board[l][k] == '.') continue;
                        if(st.count(board[l][k]) != 0) return false;
                        st.insert(board[l][k]);
                    }
                }
            }
        }
        return true;
    }
};
