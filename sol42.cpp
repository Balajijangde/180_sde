class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max, diff;
        max = diff = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                diff++;
            }else{
                if(max < diff)
                    max = diff;
                diff = 0;
                
            }
        if(diff > max)
            max = diff;
        
        }
        return max;
    }
};