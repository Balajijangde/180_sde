class Solution {
  public:
    int recur(string s, string t, int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0)
            return 0;
        else if(m == 0 || n == 0)
            return max(m, n);
        if(dp[m][n] != -1)
            return dp[m][n];
        if(s[m-1] == t[n-1]){
            return dp[m][n] = recur(s, t, m-1, n-1, dp);
        }else{
            //take min cost of replacing inserting and removing
            return dp[m][n] = 1+min(min(recur(s, t, m, n-1, dp),recur(s, t, m-1, n, dp)),recur(s, t, m-1, n-1, dp)); 
        }
    }
    int editDistance(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));
        int result = recur(s, t, s.size(), t.size(), dp);
        return result;
    }
};