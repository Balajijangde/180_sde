class Solution {
public:
    int moveRobot(int rows, int columns, int m, int n){
        if(m >= rows || n >= columns)
            return 0;
        if(m == rows-1 && n == columns-1)
            return 1;
        else
            return moveRobot(rows, columns, m+1, n) + moveRobot(rows, columns, m, n+1);
    }
    int uniquePaths(int m, int n) {
        return moveRobot(m, n, 0, 0);
    }
};