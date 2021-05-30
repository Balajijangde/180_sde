class Solution {
public:
    void recur(int i,int target, vector<int> &arr, vector<vector<int>> &result, vector<int> &can){
        if(target == 0){
            result.push_back(arr);
            return;
        }
        if(i >= can.size() || target <0)
            return;
        
        //not picking the element
        recur(i+1, target, arr, result, can);
        //picking the element
        arr.push_back(can[i]);
        recur(i, target-can[i], arr, result, can);
        arr.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> arr;
        recur(0, target, arr, result, candidates);
        return result;
    }
};