class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i] == needle[0]){
                for(int j=0; j<needle.size(); j++){
                    int first = i+j;
                    int second = j;
                    if(haystack[first] != needle[second])
                        break;
                    if(haystack[first] == needle[second] && second == needle.size()-1)
                        return i;
                    
                }
            }
        }
        return -1;
    }
};