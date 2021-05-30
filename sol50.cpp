class Solution {
public:
    void recur(int index, int target, vector<int> &arr, vector<int> &can, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(arr);
            return;
        }
        if(target < 0)
            return;
        
        for(int i=index+1; i<=can.size(); i++){
            if(i-1 != 0 && can[i-1] == can[i-2] && i != index+1)
                continue;
            arr.push_back(can[i-1]);
            recur(i, target-can[i-1], arr, can, result);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        recur(0, target, arr, candidates, result);
        return result;
    }
};