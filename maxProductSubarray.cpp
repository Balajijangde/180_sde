class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> min_array;
        vector<int> max_array;
        int result = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                min_array.push_back(nums[i]);
                max_array.push_back(nums[i]);
            }else if(nums[i] == 0){
                min_array.push_back(1);
                max_array.push_back(1);
            }else{
                min_array.push_back(min(nums[i], min(nums[i]*min_array[i-1], nums[i]*max_array[i-1])));
                max_array.push_back(max(nums[i], max(nums[i]*max_array[i-1], nums[i]*min_array[i-1])));
            }
            if(max_array[i] == min_array[i] && nums[i] == 0){
                if(0 > result) result = 0;
            }else{
                if(max(min_array[i], max_array[i]) > result) result = max(min_array[i], max_array[i]);
            }
            
        }
        return result;
    }
};