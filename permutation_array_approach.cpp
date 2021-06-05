//find all permutation using more space approach

#include<bits/stdc++.h>
using namespace std;

void recur(vector<int> &nums, vector<int> &permutation, vector<vector<int>> &result, vector<int> &record) {
	bool isFinished = true;
	for (int i = 0; i < nums.size(); i++) {
		if (record[i] == 0) {
			isFinished = false;
			permutation.push_back(nums[i]);
			record[i] = 1;
			recur(nums, permutation, result, record);
			permutation.pop_back();
			record[i] = 0;
		}
	}
	if (isFinished) {
		result.push_back(permutation);
		return;
	}
}

int main() {
	vector<vector<int>> result;
	vector<int> permutation;
	vector<int> nums{ 1, 2, 3 };
	vector<int> record(nums.size(), 0);
	recur(nums, permutation, result, record);
	return 0;
}