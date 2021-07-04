class Solution {
public:
    struct Node {
	int time = 0;
	int x = 0;
	int y = 0;
	Node(int t, int x, int y) {
		time = t;
		this->x = x;
		this->y = y;
	}
};
    int orangesRotting(vector<vector<int>>& grid) {
    queue<Node> record;
	int lastTime = 0;
    bool allBlanks = true;
	//make record for all rottten oranges
	for (int m = 0; m < grid.size(); m++) {
		for (int n = 0; n < grid[0].size(); n++) {
			if (grid[m][n] == 2) {
				record.push(Node(0, n, m));
			}else if(grid[m][n] == 1){
                allBlanks = false;
            }
		}
	}
	if (record.empty()){
        if(allBlanks)
            return 0;
        else
            return -1;
    }
		
	//increase time frame and rott the oranges
	while (!record.empty()) {
		Node temp(record.front().time, record.front().x, record.front().y);
		lastTime = record.front().time;
		record.pop();
		//check and rott left
		if (temp.x != 0) {
			if (grid[temp.y][temp.x - 1] == 1) {
				grid[temp.y][temp.x - 1] = 2;
				record.push(Node(temp.time+1, temp.x-1, temp.y));
			}
		}
		//check and rott top
		if (temp.y != 0) {
			if (grid[temp.y - 1][temp.x] == 1) {
				grid[temp.y - 1][temp.x] = 2;
				record.push(Node(temp.time + 1, temp.x, temp.y - 1));
			}
		}
		//check and rott right
		if (temp.x != (grid[0].size() - 1)) {
			if (grid[temp.y][temp.x + 1] == 1) {
				grid[temp.y][temp.x + 1] = 2;
				record.push(Node(temp.time + 1, temp.x + 1, temp.y));
			}
		}
		//check and rott bottom
		if (temp.y != (grid.size() - 1)) {
			if (grid[temp.y + 1][temp.x] == 1) {
				grid[temp.y + 1][temp.x] = 2;
				record.push(Node(temp.time + 1, temp.x, temp.y + 1));
			}
		}
		

	}
	//check for un rotten oranges
	for (int m = 0; m < grid.size(); m++) {
		for (int n = 0; n < grid[0].size(); n++) {
			if (grid[m][n] == 1) {
				return -1;
			}
		}
	}
	return lastTime;
    }
};