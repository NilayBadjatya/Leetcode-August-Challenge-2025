class Solution {
public:

    int solve1(vector<vector<int>>& grid, int i, int j, int eleToBe, bool canChange, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] != eleToBe){
            return 0;
        }
        if(grid[i][j] == 2){
            eleToBe = 0;
        }else{
            eleToBe = 2;
        }
        if(!canChange){
            return 1 + solve1(grid, i+1, j-1, eleToBe, canChange, n, m);  
        }
        int take = 1 + solve1(grid, i+1, j+1, eleToBe, canChange, n, m);
        if(canChange){
            take = max(take, 1 + solve1(grid, i+1, j-1, eleToBe, false, n, m));
        }
        return take;
    }

    int solve2(vector<vector<int>>& grid, int i, int j, int eleToBe, bool canChange, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] != eleToBe){
            return 0;
        }
        if(grid[i][j] == 2){
            eleToBe = 0;
        }else{
            eleToBe = 2;
        }
        int take = 0;
        if(!canChange){
            return 1 + solve2(grid, i-1, j-1, eleToBe, canChange, n, m);
        }
        take = 1 + solve2(grid, i+1, j-1, eleToBe, canChange, n, m);
        if(canChange){
            take = max(take, 1 + solve2(grid, i-1, j-1, eleToBe, false, n, m));
        }
        return take;
    }

    int solve3(vector<vector<int>>& grid, int i, int j, int eleToBe, bool canChange, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] != eleToBe){
            return 0;
        }
        if(grid[i][j] == 2){
            eleToBe = 0;
        }else{
            eleToBe = 2;
        }
        int take = 0;
        if(!canChange){
            return 1 + solve3(grid, i-1, j+1, eleToBe, canChange, n, m);  
        }
        take = 1 + solve3(grid, i-1, j-1, eleToBe, canChange, n, m);      
        if(canChange){
            take = max(take, 1 + solve3(grid, i-1, j+1, eleToBe, false, n, m));  
        }
        return take;
    }

    int solve4(vector<vector<int>>& grid, int i, int j, int eleToBe, bool canChange, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] != eleToBe){
            return 0;
        }
        if(grid[i][j] == 2){
            eleToBe = 0;
        }else{
            eleToBe = 2;
        }
        int take = 0;
        if(!canChange){
            return 1 + solve4(grid, i+1, j+1, eleToBe, canChange, n, m);  
        }
        take = 1 + solve4(grid, i-1, j+1, eleToBe, canChange, n, m);      
        if(canChange){
            take = max(take, 1 + solve4(grid, i+1, j+1, eleToBe, false, n, m));  
        }
        return take;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int len = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    len = max(len, 1 + solve1(grid, i+1, j+1, 2, true, n, m));
                    len = max(len, 1 + solve2(grid, i+1, j-1, 2, true, n, m));
                    len = max(len, 1 + solve3(grid, i-1, j-1, 2, true, n, m));
                    len = max(len, 1 + solve4(grid, i-1, j+1, 2, true, n, m));
                }
            }
        }
        return len;
    }
};
