// int recur(vector<int> &A, vector<int> &B, int C, int N, vector<vector<int>> &dp){
//     if(C == 0 || N == 0)
//         return 0;
//     if(dp[N][C] != -1)
//         return dp[N][C];
//     if(C >= B[N-1]){
//         return dp[N][C] = max(A[N-1]+recur(A, B, C-B[N-1], N-1, dp), recur(A, B, C, N-1, dp));
//     }else{
//         return dp[N][C] = recur(A, B, C, N-1, dp);
//     }
// }

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<vector<int>> dp(A.size()+1, vector<int> (C+1, -1));
    //initialization
    for(int i=0; i<A.size()+1; i++){
        for(int j=0; j<C+1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    //decision tree
    for(int i=1; i<A.size()+1; i++){
        for(int j=1; j<C+1; j++){
            if(j >= B[i-1]){
                dp[i][j] = max(A[i-1]+dp[i-1][j-B[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[A.size()][C];
}
