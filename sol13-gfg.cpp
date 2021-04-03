// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int row = 0;
	    int column = M-1;
	    if(X < mat[0][0] || X > mat[N-1][M-1])
	        return 0;
	    while(row < N && column >= 0){
	        if(mat[row][column] == X){
	            return 1;
	        }else if(mat[row][column] < X){
	            row++;
	        }else{
	            column--;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  // } Driver Code Ends