class Solution{
    void recur(int x, int y, vector<string>& result,string &path, vector<vector<int>>& m, int n) {
	//base condition
	
	if (x == n - 1 && y == n - 1) {
		result.push_back(path);
		return;
	}
	//test conditions
	if (y != n - 1 && m[y + 1][x] == 1) {
		//go down
		m[y][x] = 0;
		path.push_back('D');
		recur(x, y + 1, result, path, m, n);
		path.pop_back();
		m[y][x] = 1;
	}
	if (x != 0 && m[y][x - 1] == 1) {
		//go left
		m[y][x] = 0;
		path.push_back('L');
		recur(x - 1, y, result, path, m, n);
		path.pop_back();
		m[y][x] = 1;
	}
	if (x != n - 1 && m[y][x + 1] == 1) {
		//go right
		m[y][x] = 0;
		path.push_back('R');
		recur(x + 1, y, result, path, m, n);
		path.pop_back();
		m[y][x] = 1;
	}
	if (y != 0 && m[y - 1][x] == 1) {
		//go up
		m[y][x] = 0;
		path.push_back('U');
		recur(x, y - 1, result, path, m, n);
		path.pop_back();
		m[y][x] = 1;
	}
	
	
	
	return;
}
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        string path;
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return result;
        }else{
            recur(0,0,result,path,m,n);
        }
        return result;
        
    }
};