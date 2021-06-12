class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        
	if (m < n) return kthElement(arr2, arr1, m, n, k);
	int low = max(0, k-m);
	int high = min(n, k);
	int cut1 = 0;
	int cut2 = 0;
	while (low <= high) {
		cut1 = (low + high) / 2;
		cut2 = k - cut1;
		int l1 = (cut1 - 1 >= 0 && cut1 - 1 < n) ? arr1[cut1 - 1] : INT_MIN;
		int l2 = (cut2 - 1 >= 0 && cut2 - 1 < m) ? arr2[cut2 - 1] : INT_MIN;
		int r1 = (cut1 >= 0 && cut1 < n) ? arr1[cut1] : INT_MAX;
		int r2 = (cut2 >= 0 && cut2 < m) ? arr2[cut2] : INT_MAX;
		if (l1 <= r2 && l2 <= r1) {
			//cuts are  perfect
			return max(l1, l2);
		}
		else {
			if (l1 > r2) {
				high = cut1 - 1;
			}
			else {
				low = cut1 + 1;
			}
		}
	}	
	
    }
};