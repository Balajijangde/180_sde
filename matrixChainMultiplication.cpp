class Solution{
public:
    int recur(int arr[], int i, int j, vector<vector<int>> &dp){
        if(i >= j) return 0;
        int result = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i; k<j; k++){
            int tempAns = recur(arr, i, k, dp) + recur(arr, k+1, j, dp) + (arr[i-1]*arr[k]*arr[j]);
            if(tempAns < result) result = tempAns;
        }
        return dp[i][j] = result;
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp (N+1, vector<int> (N+1, -1));
        int answer = recur(arr, 1, N-1, dp);
        return answer;
    }
};