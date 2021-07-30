
// int recur(vector<int> &A, int B, int n, vector<vector<int>> &dp){
//     if(B == 0)
//         return 0;
//     if(n == 0)
//         return 0;
//     if(dp[n][B] != -1)
//         return dp[n][B];
//     if(B >= A[n-1]){
//         return dp[n][B] = max(A[n-1]+recur(A, B-A[n-1], n-1, dp), recur(A, B, n-1, dp));
//     }else{
//         return dp[n][B] = recur(A, B, n-1, dp);
//     }
// }
int Solution::solve(vector<int> &A, int B) {
    vector<vector<int>> dp(A.size()+1, vector<int> (B+1, -1));
    for(int i=0; i<A.size()+1; i++){
        for(int j=0; j<B+1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i=1; i<A.size()+1; i++){
        for(int j=1; j<B+1; j++){
            if(j >= A[i-1]){
                dp[i][j] = max(A[i-1]+dp[i-1][j-A[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[A.size()][B] == B) return 1;
    else return 0;
}