int getCount(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] <= target) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = pow(10, 9);
    int mid = 0;
    int n = A.size();
    int m = A[0].size();
    while (low <= high) {
        mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += getCount(A[i], mid);
        }
        if (count <= (n * m) / 2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}