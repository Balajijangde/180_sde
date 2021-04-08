// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    unordered_map<int, int> sums;
        int sum = 0;
        int max = 0;
        for(int i=0; i<n; i++){
            sum += A[i];
            if(sum == 0){
                if(i+1 > max){
                    max = i+1;
                }
                    
            }
                
            if(sums.find(sum) != sums.end() ){
                if(max < i - sums.at(sum)){
                    max = i - sums.at(sum);
                }
                    
            }
                
            else{
                sums.insert({sum, i});
            }
                
        }
        return max;
}
