class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        cout<<"i :"<<i<<" j :"<<j<<endl;
        visited[i][j] = true;
        //move to top
        if(i > 0 && grid[i-1][j] == '1' && !visited[i-1][j]) dfs(i-1, j, grid, visited);
        //move to bottom
        if(i < (grid.size()-1) && grid[i+1][j] == '1' && !visited[i+1][j]) dfs(i+1, j, grid, visited);
        //move to left
        if(j > 0 && grid[i][j-1] == '1' && !visited[i][j-1]) dfs(i, j-1, grid, visited);
        //move to right
        if(j < (grid[0].size()-1) && grid[i][j+1] == '1' && !visited[i][j+1]) dfs(i, j+1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        int lands = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    lands++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return lands;
    }
};