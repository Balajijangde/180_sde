class Solution {
public:
    int moveRobot(int rows, int columns, int m, int n, vector<vector<int>>& record){
        if(m >= rows || n >= columns) return 0;
        if(m == rows-1 && n == columns-1) return 1;
        if(record[m][n] != -1) return record[m][n];
        else return record[m][n] = moveRobot(rows, columns, m+1, n, record) + moveRobot(rows, columns, m, n+1, record);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> record(m, vector<int>(n, -1));
        return moveRobot(m, n, 0, 0, record);
    }
};