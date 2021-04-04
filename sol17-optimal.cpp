class Solution {
public:
    long long unsigned int uniquePaths(int m, int n) {
        int nC = m + n - 2;
        long long unsigned int result = 1;
        int target = m<=n?m:n;
        for(int i=0; i<target-1; i++){
            result = (long long unsigned int) result * (nC-i);
            result = (long long unsigned int) result/(1+i);
        }
        return result;
    }
};