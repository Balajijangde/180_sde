class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        vector<int> pair = intervals[0];
        for(int i = 1; i<intervals.size(); i++){
            //checking whether it is overlapping with current interval
            if((intervals[i][0] >= pair[0] && intervals[i][0] <= pair[1]) || (intervals[i][1] >= pair[0] && intervals[i][1] <= pair[1])){
                pair[0] = intervals[i][0] < pair[0]?intervals[i][0]:pair[0];
                pair[1] = intervals[i][1] > pair[1]?intervals[i][1]:pair[1];
            }else{
                //not overlaping than push to result vector and load next interval to pair
                result.insert(result.end(), pair);
                pair = intervals[i];
            }
                
            
        }
        result.insert(result.end(), pair);
        return result;
    }
};