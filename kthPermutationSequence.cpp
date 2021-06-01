class Solution {
public:
    int factorial(int i){
        if(i <= 1)
            return 1;
        return i*factorial(i-1);
    }
    void  recur(int n, int k, vector<int> &arr, string &result){
        if(n == 1){
            result += to_string(arr[0]);
            return;
        }
        int index = k/factorial(n-1);
        result += to_string(arr[index]);
        arr.erase(arr.begin()+index);
        recur(n-1, k%(factorial(n-1)), arr, result);
    }
    string getPermutation(int n, int k) {
        string result;
        vector<int> arr;
        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }
        recur(n, k-1, arr, result);
        return result;
    }
};