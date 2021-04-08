class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {       
        //sort the array
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        //traversing the array
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                int left = j+1;
                int right = nums.size()-1;
                int sub_target = target - (nums[i]+nums[j]);
                while(left<right){
                    int left_value, right_value;
                    if(nums[left] + nums[right] < sub_target) left++;
                    else if(nums[left] + nums[right] > sub_target) right--;
                    else{
                        vector<int> pair{nums[i], nums[j], nums[left], nums[right]};
                        result.insert(result.end(), pair);
                        while(left < right && nums[left] == result[result.size()-1][2]) ++left;
                        while(left < right && nums[right] == result[result.size()-1][3]) --right;
                    }
                }
                while(j+1 < nums.size() && nums[j+1] == nums[j]) ++j;
                
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }
        return result;
    }
};