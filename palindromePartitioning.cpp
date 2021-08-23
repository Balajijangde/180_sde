class Solution{
public:
    bool isPalindrome(string str){
        int lo = 0;
        int hi = str.size()-1;
        while(lo<hi){
            if(str[lo++] != str[hi--]) return false;
        }
        return true;
    }
    int recur(string &str, int i, int j, vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(isPalindrome(str.substr(i, j-i+1))) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int tempAns = INT_MAX;
        
        for(int k=i; k<j; k++){
            int leftAns = 0;
        if(dp[i][k] != -1) leftAns = dp[i][k];
        else leftAns = recur(str, i, k, dp);
        int rightAns = 0;
        if(dp[k+1][j] != -1) rightAns = dp[k+1][j];
        else rightAns = recur(str, k+1, j, dp);
            int temp = 1 + leftAns  + rightAns;
            tempAns = min(tempAns, temp);
        }
        return dp[i][j] = tempAns;
        
    }
    int palindromicPartition(string str)
    {
        vector<vector<int>> dp (str.size()+1, vector<int> (str.size()+1, -1));
        int result = recur(str, 0, str.size()-1, dp);
        return result;
    }
};