class Solution {
public:
    void recur(vector<vector<char>> &board, vector<vector<char>> &result){
        //find first empty place
	int row = -1;
	int col = -1;
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (board[r][c] == '.') {
				row = r;
				col = c;
				break;
			}
		}
		if (row != -1)
			break;
	}
	if (row == -1 && col == -1) {
		result = board;
		return;
	}
		
	//find all possible value

	vector<char> values{ '.', '1','2','3','4','5','6','7','8','9' };
	//search for possible values horizontaly
	for (int i = 0; i < 9; i++) {
		if (board[row][i] != '.') {
			int num = board[row][i] - '0';
			values[num] = '.';
		}
	}
	//search for possible value vertically
	for (int i = 0; i < 9; i++) {
		if (board[i][col] != '.') {
			int num = board[i][col] - '0';
			values[num] = '.';
		}
	}
	//search for possible value in local block 
	int row_low = -1;
	int row_high = -1;
	int col_low = -1;
	int col_high = -1;
	if (row < 3) {
		row_low = 0;
		row_high = 2;
	}
	else if (row < 6) {
		row_low = 3;
		row_high = 5;
	}
	else {
		row_low = 6;
		row_high = 8;
	}
	if (col < 3) {
		col_low = 0;
		col_high = 2;
	}
	else if (col < 6) {
		col_low = 3;
		col_high = 5;
	}
	else {
		col_low = 6;
		col_high = 8;
	}for (int r = row_low; r <= row_high; r++) {
		for (int c = col_low; c <= col_high; c++) {
			if (board[r][c] != '.') {
				int num = board[r][c] - '0';
				values[num] = '.';
			}
		}
	}



	//recurs with all possible values
	for (int i = 0; i < 10; i++) {
		if (values[i] != '.') {
			board[row][col] = values[i];
			recur(board, result);
			board[row][col] = '.';
		}
	}
	
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> result;
        recur(board, result);
        board = result;
        
    }
};