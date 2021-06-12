class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
    int n = nums1.size();
	int m = nums2.size();
	int low = 0;
	int high = nums1.size();
	while (true) {
		int cut1 = (low + high) / 2;
		int cut2 = ((n + m) / 2) - cut1;
		int l1 = (cut1-1>=0 && cut1-1<nums1.size())?nums1[cut1 - 1]:INT_MIN;
		int r1 = (cut1 >= 0 && cut1 <nums1.size())?nums1[cut1]:INT_MAX;
		int l2 = (cut2-1 >= 0 && cut2-1 < nums2.size())?nums2[cut2 - 1]:INT_MIN;
		int r2 = (cut2>= 0 && cut2<nums2.size())?nums2[cut2]:INT_MAX;
		if (l1 <= r2 && l2 <= r1) {
			if ((n + m) % 2 == 0) {
				double median;
				return median = ((double)max(l1, l2) + (double)min(r1, r2)) / (double)2;
			}
			else {
				double median;
				return (double)min(r1, r2);
			}
		}
		else {
			if (l1 > r2) 
				high = cut1 - 1;
			else
				low = cut1 + 1;
		}
	}
    }
};