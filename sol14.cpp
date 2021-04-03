class Solution {
public:
    double myPowPlus(double x,long int n){
        if(n == 0)
            return 1;
        else if(n%2 == 0){
            return myPowPlus(x*x, n/2);
        }
        else{
            return x * myPowPlus(x, n-1);
        }
    }
    double myPow(double x,long int n) {
        if(n >= 0){
            return myPowPlus(x, n);
        }else{
            double res = myPowPlus(x, abs(n));
            return (double)1/res;
        }
    }
};