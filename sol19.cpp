class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(record.find(target-nums[i]) != record.end()){
                
                result.insert(result.end(), record.at(target-nums[i])) ;
                result.insert(result.end(), i) ;
                return result;
            }else{
                record.insert({nums[i], i});
            }
        }
        return result;
    }
};