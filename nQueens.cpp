class Solution {
public:
    void recur(int row, int n, int queen, vector<vector<string>> &result, vector<string> &board, vector<int> &h, vector<int> &dDiagonal, vector<int> &iDiagonal) {
	if (queen == 0) {
		result.push_back(board);
		return;
	}
	for (int i = 0; i < n; i++) {
		//check for placement
		if (h[i] == 0 && iDiagonal[n - i - 1 + row] == 0 && dDiagonal[row + i] == 0) {
			h[i] = 1;
			iDiagonal[n - i - 1 + row] = 1;
			dDiagonal[row + i] = 1;
			board[row][i] = 'Q';
			recur(row + 1, n, queen - 1, result, board, h, dDiagonal, iDiagonal);
			board[row][i] = '.';
			dDiagonal[row + i] = 0;
			iDiagonal[n - i - 1 + row] = 0;
			h[i] = 0;

		}
		
	}
	return;
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
	vector<string> board;
	string demo;
	for (int i = 0; i < n; i++) {
		demo.push_back('.');
	}
	for (int i = 0; i < n; i++) {
		board.push_back(demo);
	}
	vector<int> h(n, 0);
	int size = ((n - 1) * 2) + 1;
	vector<int> dDiagonal(size, 0);
	vector<int> iDiagonal(size, 0);
	recur(0, n, n, result, board, h, dDiagonal, iDiagonal);
	return result;
    }
};