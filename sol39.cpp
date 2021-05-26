class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }
        sort(nums.begin(), nums.end());
        int a, b, c, vala, valb, valc;
        a = 0;
        for(int i=0; i<nums.size()-2;i++){
            if(vala == nums[i])
                continue;
            vala = nums[i];
            b=i+1;
            c=nums.size()-1;
            //have to put some conditions here
            while(b<c){
                
                if(nums[i]+nums[b]+nums[c] < 0){
                    valb = nums[b];
                    while(valb == nums[b]){
                        if(b <c){
                            b++;
                        }else{
                            break;
                        }
                    }
                        
                }else if(nums[i]+nums[b]+nums[c] > 0){
                    valc = nums[c];
                    while(valc == nums[c]){
                        if(c > b){
                            c--;
                        }else{
                            break;
                        }
                    }
                        
                }else{
                    //insert value to result;
                    vector<int> vect{nums[i], nums[b], nums[c]};
                    result.push_back(vect);
                    valb = nums[b];
                    valc = nums[c];
                    while(valb == nums[b]){
                        if(b <c){
                            b++;
                        }else{
                            break;
                        }
                    }
                    while(valc == nums[c]){
                        if(c > b){
                            c--;
                        }else{
                            break;
                        }
                    }
                        
                        
                }
            }
            
            
        }
        return result;
    }
};