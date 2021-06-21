class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
	stack<int> record;
	int length = (2 * nums.size()) - 1;
	for (int i = length; i >= 0; i--) {
		int current = nums[i % nums.size()];
		if (record.empty()) {
			result[i % nums.size()] = -1;
			record.push(current);
		}
		else if (record.top() <= current) {
			while (!record.empty() && record.top() <= current) {
				record.pop();
			}
			if (record.empty()) {
				result[i % nums.size()] = -1;
				record.push(current);
			}
			else {
				result[i % nums.size()] = record.top();
				record.push(current);
			}
		}
		else {
			result[i % nums.size()] = record.top();
			record.push(current);
		}
	}
	return result;
    }
};