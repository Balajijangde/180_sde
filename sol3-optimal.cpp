// { Driver Code Starts
#include <iostream> 
using namespace std; 


 // } Driver Code Ends


class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap;
            if((n+m)%2 != 0){
                gap = ((n+m)/2)+1;
            }else{
                gap = (n+m)/2;
            }
            
            
            while(1 == 1){
                for(int counter = 0; counter < n+m; counter++){
                if(counter+gap-n >= m){
                    break;
                }
                //comparing in first array
                if((counter + gap) <= n ){
                    if(arr1[counter] > arr1[counter+gap]){
                        swap(arr1[counter], arr1[counter+gap]);
                    }
                }
                
                //comparing in both arrays
                if(counter <= n -1 && (counter + gap) > n-1){
                    if(arr1[counter] > arr2[counter+gap-n]){
                        swap(arr1[counter], arr2[counter+gap-n]);
                    }
                }
                //comparing in second array
                if(counter> n-1){
                    if(arr2[counter-n]>arr2[counter+gap-n]){
                        swap(arr2[counter-n], arr2[counter+gap-n]);
                    }
                }
            }
            if(gap == 1 || gap == 0){
                break;
            }else if(gap%2 != 0){
                gap = (gap/2) +1;
            }else{
                gap = gap/2;
            }
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
    long long arr1[] = {1,3,5,7};
    long long arr2[] = {0,2,6,8,9};
    int n = 4;
    int m = 5;
	
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	

	return 0; 
} 
  // } Driver Code Ends