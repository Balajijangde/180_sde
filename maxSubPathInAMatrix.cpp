class Solution {
public:
    int recur(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            return grid[i][j];
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        else if(i == grid.size()-1){
            return dp[i][j] = grid[i][j] + recur(grid, i,j+1, dp);
        }else if(j == grid[0].size()-1){
            return dp[i][j] = grid[i][j] + recur(grid, i+1, j, dp);
        }else{
            return dp[i][j] = grid[i][j] + min(recur(grid, i+1, j, dp), recur(grid, i, j+1, dp));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size()+1, vector<int> (grid[0].size()+1, -1));
        int result = recur(grid, 0, 0, dp);
        return result;
    }
};