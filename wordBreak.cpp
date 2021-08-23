class Solution {
public:
    bool recur(int i, int j, string s, unordered_set<string> &wordSet, vector<vector<int>> &dp){  
        if(i > j) return false;
        else if(i == j){
            if(wordSet.find(s.substr(i, 1)) != wordSet.end()){
                return true;
            }else{
                return false;
            }
        }
        else if(wordSet.find(s.substr(i, j-i+1)) != wordSet.end()) return true;
        if(dp[i][j] != -1 ) return dp[i][j] == 1;
            bool temp = false;
            for (int k = i; k < j; k++) {
                bool leftAns;
                if (dp[i][k] != -1) leftAns = dp[i][k];
                else leftAns = recur(i, k, s, wordSet, dp);
                bool rightAns;
                if (dp[k + 1][j] != -1) rightAns = dp[k + 1][j];
                else rightAns = recur(k + 1, j, s, wordSet, dp);
                bool tempAns = leftAns && rightAns;
                temp = tempAns || temp;
        }
        if(temp == true) dp[i][j] = 1;
        else dp[i][j] = 0;
        return temp;
        }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //preparing word set
        unordered_set<string> wordSet;
        for(int i=0; i<wordDict.size(); i++){
            wordSet.insert(wordDict[i]);
        }
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, -1));
        bool finalRes = recur(0, s.size()-1, s, wordSet, dp);
        return finalRes;
        
    }
};
int main(){
    Solution sol;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabab";
    vector<string> wordMap = {"a", "aa", "ba"};
    sol.
}