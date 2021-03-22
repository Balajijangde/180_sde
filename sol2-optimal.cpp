// { Driver Code Starts
#include <iostream>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        //got sum and sum of squares
        long long int sum = (long long int)((long long int)n * (long long int)(n+1))/2;
        long long int sq_sum = (long long int)((long long int)n * (long long int)(n+1) * (long long int)(2*n+1))/6;
        
        //calculating term1 and term2
        for(int i=0; i<n; i++){
            sum -= (long long int)arr[i];
            sq_sum -= (long long int)arr[i]*(long long int)arr[i];
        }
        
        //calculating x and y
        int x = (sum + (sq_sum/sum))/2;
        int y = x - sum;
        
        int result[] = {y, x};
        int *result_ptr = result;
        
        return result_ptr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends