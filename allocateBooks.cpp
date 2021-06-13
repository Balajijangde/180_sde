bool isPossible(int mid, int b, vector<int>& nums) {
	int student = 1;
	int pages = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > mid) return false;
		pages += nums[i];
		if (pages > mid) {
			student++;
			pages = nums[i];
		}
	}
	if (student > b || pages > mid)
		return false;
	return true;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    int low, high;
	low = INT_MAX;
	high = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] < low) low = A[i];
		high += A[i];
	}
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (isPossible(mid, B, A)) high = mid - 1;
		else low = mid + 1;
	}
	return low;
}