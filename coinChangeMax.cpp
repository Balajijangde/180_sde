class Solution
{
  public:
    // long long int recur(int S[], int m, int n, vector<vector<long long>> &dp){
    //     if(n == 0) return 1;
    //     if(m == 0) return 0;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     if(n >= S[m-1]){
    //         return dp[m][n] = recur(S, m, n-S[m-1], dp) + recur(S, m-1, n, dp);
    //     }else{
    //         return dp[m][n] = recur(S, m-1, n, dp);
    //     }
    // }
    long long int count( int S[], int m, int n )
    {
        vector<vector<long long>> dp(m+1, vector<long long> (n+1, -1));
    //   long long int result = recur(S, m, n, dp);
    //   return result;
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;  
            }
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(j >= S[i-1]){
                    dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
        
    }
};