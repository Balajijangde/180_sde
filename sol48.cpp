class Solution {
public:
    void recur(int index, vector<int> arr, vector<int> &nums, vector<vector<int>> &result){
        // if(index >= nums.size())
        //     return;
        //add the data structure you have in result;
        result.push_back(arr);
        
        
        for(int i=index+1; i<=nums.size(); i++){
            if(i!=index+1 && nums[i-1] == nums[i-2])
                continue;
            arr.push_back(nums[i-1]);
            recur(i, arr, nums, result);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> arr;
        recur(0, arr, nums, result);
        return result;
        
        
    }
};