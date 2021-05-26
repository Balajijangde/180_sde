class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)
            return 0;
        
        int left, right, leftmax, rightmax, res;
        left = leftmax = rightmax = res = 0;
        right = height.size()-1;
        while(left<=right){
            if(height[left] <= height[right]){
                if(height[left] >= leftmax){
                    leftmax = height[left];
                    left++;
                }else{
                    res += leftmax - height[left];
                    left++;
                }
            }else{
                if(height[right] >= rightmax){
                    rightmax = height[right];
                    right--;
                }else{
                    res += rightmax - height[right];
                    right--;
                }
            }
        }
        return res;
    }
};