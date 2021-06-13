class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        if(n == 0)
            return false;
        long long m =  n-(long long)1;
        return (n & m) == 0;
    }
};