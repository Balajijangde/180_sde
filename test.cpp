#include<iostream>

using namespace std;

int main(){
    int n = 2017;
    long long int sum = (n * (n+1))/2;
    long long int sq_sum = (long long int)((long long int)n * (long long int)(n+1) * (long long int)((2*n)+1))/6;
    cout<<sum<<endl;
    cout<<sq_sum<<endl;
    return 0;
}