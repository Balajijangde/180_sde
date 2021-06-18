#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSets(vector<int>& nums) {
	vector<vector<int>> result;
	for (int i = 0; i < pow(2, nums.size()); i++) {
		vector<int> res;
		for (int j = 0; j < nums.size(); j++) {
			if (((i >> j) & 1) == 1) {
				res.push_back(nums[j]);
			}
		}
		result.push_back(res);
	}
	return result;
}
int main() {
	vector<int> nums{1,2,3};
	vector<vector<int>> result = powerSets(nums);
	return 1;
}