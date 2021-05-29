class Solution
{
public:
    void func(int index, int sum, int N, vector<int> &arr, vector<int> &result){
        if(index == N){
            result.push_back(sum);
            return;
        }
        //picking the element
        func(index+1, sum+arr[index], N, arr, result);
        //not picking the element
        func(index+1, sum, N, arr, result);
    }


    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> result;
        func(0, 0, N, arr, result);
        int element = pow(2, N);
        sort(result.begin(), result.end());
        return result;
    }
};