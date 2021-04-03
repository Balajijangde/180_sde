class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1 = -1;
        int nums2 = -1;
        int c1 = 0;
        int c2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums1)
                c1++;
            else if(nums[i] == nums2)
                c2++;
            else if(c1 == 0){
                nums1 = nums[i];
                c1 = 1;
            }else if(c2 == 0){
                nums2 = nums[i];
                c2 = 1;
            }else{
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for(int num: nums){
            if(num == nums1)
                c1++;
            else if(num == nums2)
                c2++;
        }
        vector<int> result;
        if(c1 > floor(nums.size()/3))
            result.insert(result.end(), nums1);
        if(c2 > floor(nums.size()/3))
            result.insert(result.end(), nums2);
        
        
        return result;
    }
};