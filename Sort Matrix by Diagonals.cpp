class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // For bottom left triangle
        for(int i = 0; i < n; i++){
            int row = i, col = 0;
            vector<int> temp;
            while(row < n && col < n){
                temp.push_back(grid[row++][col++]);
            }
            sort(temp.begin(), temp.end(), greater<int>());
            row = i, col = 0;
            while(row < n && col < n){
                grid[row][col] = temp[col];
                row++;
                col++;
            }
        }

        // For top right triangle
        for(int j = 1; j < n; j++){
            int row = 0, col = j;
            vector<int> temp;
            while(row < n && col < n){
                temp.push_back(grid[row++][col++]);
            }
            sort(temp.begin(), temp.end());
            row = 0, col = j;
            while(row < n && col < n){
                grid[row][col] = temp[row];
                row++;
                col++;
            }
        }

        return grid;
    }
};
