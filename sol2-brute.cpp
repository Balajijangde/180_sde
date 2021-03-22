#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_set<int> nums;
        int repeated;
        int missing;
        for(int m=0; m<n; m++){
            
            if(nums.find(arr[m]) != nums.end()){
                repeated = arr[m];
               
            }else{
                
                nums.insert(arr[m]);
            }
        }
        
        for(int v=1; v<=n; v++){
            if(nums.find(v) == nums.end()){
                missing = v;
                break;
            }
        }
        
        int solution[] = {repeated, missing};
        int *sol = solution;
        return sol;
    }
};

int main() {
        int a[] = {1, 3, 3};
        int n = 3;
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        
        cout << ans[0] << " " << ans[1] << "\n";
    
    return 0;
}  