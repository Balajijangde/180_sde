#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		vector<int> left_limit(heights.size());
		vector<int> right_limit(heights.size());
		stack<int> mystack;
		stack<int> rightstack;
		int maxArea = 0;
		//filling left_limit stack
		for (int i = 0; i < heights.size(); i++) {
			if (mystack.empty()) {
				left_limit[i] = 0;
				mystack.push(i);
			}
			else {
				while (!mystack.empty() && heights[mystack.top()] >= heights[i]) {
					mystack.pop();
				}
				if (mystack.empty()) {
					left_limit[i] = 0;
					mystack.push(i);
				}
				else {
					left_limit[i] = mystack.top() + 1;
					mystack.push(i);
				}
			}
		}
		for (int i = heights.size() - 1; i >= 0; i--) {
			if (rightstack.empty()) {
				right_limit[i] = heights.size();
				rightstack.push(i);
			}
			else {
				while (!rightstack.empty() && heights[rightstack.top()] >= heights[i]) {
					rightstack.pop();
				}
				if (rightstack.empty()) {
					right_limit[i] = heights.size();
					rightstack.push(i);
				}
				else {
					right_limit[i] = rightstack.top() ;
					rightstack.push(i);
				}
			}
		}
		for (int i = 0; i < heights.size(); i++) {
			int width = abs(left_limit[i] - right_limit[i]);
			int area = width * heights[i];
			if (area > maxArea)
				maxArea = area;
		}
		return maxArea;
	}
};
int main() {
	Solution sol;
	vector<int> heights{2,4};
	int answer = sol.largestRectangleArea(heights);
	return 1;
}