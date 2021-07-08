class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int index = 0;
        if(strs[0].size() == 0)
            return result;
        while(true){
            if(index>=strs[0].size())
                break;
            for(int i=0; i<strs.size(); i++){
                if(index<strs[i].size()){
                    if(strs[i][index] != strs[0][index])
                        goto evaluate;
                }else{
                    goto evaluate;
                }
                
            }
             result+=strs[0][index];
            index++;   
            
        }
        evaluate:
        return result;
            
    }
};