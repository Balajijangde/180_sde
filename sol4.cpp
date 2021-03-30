class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = 0;
        for(int i=0; i<nums.size();i++){
            if(i == 0)
                max = nums[i];
            sum += nums[i];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
            
        }
        return max;
    }
};