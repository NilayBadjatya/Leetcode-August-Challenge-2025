class Solution {
public:
    int dp[301][301];
    int solve(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(i == m || j == n || !matrix[i][j]) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = 1 + solve(matrix, i, j+1, m, n);
        int down = 1 + solve(matrix, i+1, j, m, n);
        int diag = 1 + solve(matrix, i+1, j+1, m, n);
        return dp[i][j] = min({right, down, diag});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int count = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    count += solve(matrix, i, j, m, n);
                }
            }
        }

        return count;

    }
};
