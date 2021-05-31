class Solution {
private:
    bool isPalindrome(string &s, int start, int end){
      while(start<=end){
        if(s[start++] != s[end--])
            return false;
        }
        return true; 
    } 
    
    
    void recur(int index, vector<string> &path, string &s, vector<vector<string>> &result){
        if(index == s.size()){
            result.push_back(path);
            return;
        }
        for(int i = index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                recur(i+1, path, s, result);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        recur(0, path, s, result);
        return result;
    }
};