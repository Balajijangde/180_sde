class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
	int high = nums.size() - 2;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		//detect whether we are in left half or not
		//if we are in left half then index (1st ins, even index)(2nd ins, odd index)
		if (mid % 2 == 0) {
			//on the even index
			if (nums[mid + 1] == nums[mid]) {
				//on left half
				low = mid + 1;
			}
			else {
				//on right half
				high = mid - 1;
			}
		}
		else {
			//on the odd index
			if (nums[mid - 1] == nums[mid]) {
				//on left half
				low = mid + 1;
			}
			else {
				//on right half
				high = mid - 1;
			}
		}
	}
	return nums[low];
    }
};