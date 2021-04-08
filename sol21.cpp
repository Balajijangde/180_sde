class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        unordered_set<int> nums_set;
        for(int i = 0; i < nums.size(); i++)
            nums_set.insert(nums[i]);
        
        for(int i = 0; i < nums.size(); i++){
            if(nums_set.find(nums[i]-1) != nums_set.end())
                continue;
            int output = 1;
            int counter = 1;
            while(nums_set.find(nums[i]+counter) != nums_set.end()){
                output++;
                counter++;
                
            }
            counter = 0;
            if(output > max)
                max = output;
        }
        return max;
    }
};