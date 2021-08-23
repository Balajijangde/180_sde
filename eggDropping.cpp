class Solution
{
    public:
    int recur(int eggs, int floors, vector<vector<int>> &dp){
        if(floors == 0 || floors == 1){
            return floors;
        }
        if(eggs == 1){
            return floors;
        }
        if(dp[eggs][floors] != -1) return dp[eggs][floors];
        int tempAns = INT_MAX;
        for(int k=1; k<=floors; k++){
            int temp =  1 + max(recur(eggs-1, k-1, dp), recur(eggs, floors-k, dp));
            tempAns = min(temp, tempAns);
        }
        return dp[eggs][floors] = tempAns;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1)); 
        int result = recur(n, k, dp);
        return result;
    }
};