//Don't know why it gives segmentation fault
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long int count = 0;
    void merge(long long leftArray[], long long rightArray[], long long mainArray[], long long nl, long long nr){
        long long i = 0,  j = 0, k = 0;
        while(i<nl && j<nr){
            if(leftArray[i] <= rightArray[j])
                mainArray[k++] = leftArray[i++];
            else{
                this->count += nl - i;
                mainArray[k++] = rightArray[j++];
            }
        }
        while(i<nl)
            mainArray[k++] = leftArray[i++];
        while(j<nr)
            mainArray[k++] = rightArray[j++];
    }
    int mergeSort(long long int mainArray[], long long int N){
        if(N < 2)
            return 0;
        long long int mid = (long long int) N/2;
        long long int leftArray[mid];
        long long int rightArray[N-mid];
        
        for(long long i=0; i<mid; i++)
            leftArray[i] = mainArray[i];
        for(long long i=mid; i<N; i++)
            rightArray[i-mid] = mainArray[i];
            
        mergeSort(leftArray, mid);
        mergeSort(rightArray, N-mid);
        merge(leftArray, rightArray, mainArray, mid, N-mid);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, N);
        return this->count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends