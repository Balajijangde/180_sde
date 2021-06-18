class Solution {
  public:
    int setBits(int N) {
        if(N == 0) return 0; 
        int count = 1;
        int n = N;
        while((n & (n-1)) != 0){
            count++;
            n = (n & (n-1));
        }
        return count;
    }
};