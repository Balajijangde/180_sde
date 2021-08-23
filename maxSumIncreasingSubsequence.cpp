class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp (n, 1);
	    dp[0] = arr[0];
	    int maxSum = arr[0];
	    for(int i=1; i<n; i++){
	        
	        int amount = 0;
	        for(int j=i-1; j>=0; j--){
	            if(arr[j] < arr[i]){
	                if(arr[i]+dp[j] > amount) amount = arr[i]+dp[j];
	            }
	        }
	        dp[i] = max(amount, arr[i]);
	        if(dp[i] > maxSum) maxSum = dp[i];
	    }
	    return maxSum;
	}  
};