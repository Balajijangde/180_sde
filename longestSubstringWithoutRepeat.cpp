class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<string, int> record;
        int l=0, r=0, count=0;
        while(r<s.size()){
            if(record.find(to_string(s[r])) != record.end()){
                if((int)record[to_string(s[r])]+1 > l){
                    l = (int)record[to_string(s[r])]+1;
                }
                
                record.erase(to_string(s[r]));
            }else{
                record[to_string(s[r])] = r;
                count = (r-l)+1>count?(r-l)+1:count;
                r++;
            }
        }
        return count;
    }
};