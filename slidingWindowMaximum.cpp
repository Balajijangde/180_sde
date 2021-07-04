class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //phase one
        vector<int> result;
        deque<int> window;
        for(int i=0; i<k; i++){
            if(window.empty()){
                window.push_back(i);
            }else{
                if(nums[window.back()]>=nums[i]){
                    window.push_back(i);
                }else{
                    while(!window.empty() && nums[window.back()]<nums[i]){
                        window.pop_back();
                    }
                    window.push_back(i);
                }
            }
        }
        result.push_back(nums[window.front()]);
        //phase two
        for(int i=k; i<nums.size();i++){
            if(window.front()<=(i-k))
                window.pop_front();
            if(nums[window.back()]>=nums[i]){
                    window.push_back(i);
                    result.push_back(nums[window.front()]);
                }else{
                    while(!window.empty() && nums[window.back()]<nums[i]){
                        window.pop_back();
                    }
                    window.push_back(i);
                    result.push_back(nums[window.front()]);
                }
        }
        
        return result;
    }
};