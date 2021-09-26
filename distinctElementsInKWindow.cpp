class Solution{
  public:
  
    vector <int> countDistinct (int A[], int n, int k)
    {
        int distinct = 0;
        unordered_map<int, int> nums;
        vector<int> result;
        
        for(int i=0; i<n; i++){
            if(i <= k-1){
                if(nums.find(A[i]) == nums.end()){
                    distinct++;
                    nums[A[i]] = 1;
                }else if(nums.find(A[i]) != nums.end()){
                    nums[A[i]] += 1;
                }
                if(i == k-1){
                    result.push_back(distinct);
                }
            }else{
                nums[A[i-k]] -= 1;
                if(nums[A[i-k]] == 0){
                    distinct--;
                }
                if(nums.find(A[i]) == nums.end()){
                    distinct++;
                    nums[A[i]] = 1;
                }else if(nums[A[i]] >= 1){
                    nums[A[i]] += 1;
                }else if(nums[A[i]] == 0){
                    distinct++;
                    nums[A[i]] += 1;
                }
                result.push_back(distinct);
            }
            
        }
        return result;
    }
};