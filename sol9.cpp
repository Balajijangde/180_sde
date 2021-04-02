class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1 = 0;
        int index2 = 0;
        //finding index 1
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index1 = i;
                break;
            }
        }
        //finding index 2
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] > nums[index1]){
                index2 = i;
                break;
            }
        }
        //swapping elements on both index
        swap(nums[index1], nums[index2]);
        
        //reversing numbers
        int initial = index1 + 1;
        int final = nums.size()-1;
        if(index1 == 0 && index2 == 0){
            initial = 0;
        }
            while(initial<final)
                swap(nums[initial++], nums[final--]);
         
        
    }
};