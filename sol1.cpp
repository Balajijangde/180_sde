#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;   
        while(mid <= high){
            switch(nums[mid]){
                case 0:
                    if(mid != low){
                        swap(nums[low++], nums[mid++]);
                    }else{
                        low++;
                        mid++;
                    }
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};