class Solution {
public:
    void recur(int index, vector<int> &nums, vector<vector<int>> &result){
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            recur(index+1, nums, result);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recur(0, nums, result);
        return result;
    }
};