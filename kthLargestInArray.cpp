class Solution {
public:
    int quickSelect(vector<int> &nums, int k, int lo, int hi){
        
        int pivotValue = nums[hi];
        int boundary = lo - 1;
        for(int i=lo; i<=hi; i++){
            if(nums[i] <= pivotValue){
                boundary++;
                swap(nums[i], nums[boundary]);
            }
        }
        if(boundary == nums.size() - k){
            return nums[boundary];
        }else if(boundary < (nums.size()-k)){
            return quickSelect(nums, k, boundary+1, hi);
        }else{
            return quickSelect(nums, k, lo, boundary - 1);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int result = quickSelect(nums, k, 0, nums.size() - 1);
        return result;
    }
};