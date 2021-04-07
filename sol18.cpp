class Solution {
public:
    int count = 0;
    void merge(vector<int>& left, vector<int>& right, vector<int>& mainArray, int n, int m){
            //count reverse pairs
        int i = 0, j = 0;
        while(i < n && j < m){
            while(left[i] >(long long int) 2*right[j]){
                j++;
                if(j >= m) break;
            }   
            this->count += j;
            i++;
        }
        while(i < n && j >= m){
            this->count += j;
            i++;
        }
        //counting reverse pair finished
            
            
        
        
            i = 0; j = 0; 
        int k = 0;
            while(i < n && j < m){
                if(left[i] <= right[j])
                    mainArray[k++] = left[i++];
                else
                    mainArray[k++] = right[j++];
            }
            while(i < n)
                mainArray[k++] = left[i++];
            while(j < m)
                mainArray[k++] = right[j++];
        }
    void mergesort(vector<int>& mainArray){
            if(mainArray.size() < 2)
                return;
            int mid = mainArray.size()/2;
            vector<int> left(mid);
            vector<int> right(mainArray.size()-mid);
            for(int i=0; i<mid; i++)
                left[i] = mainArray[i];  
            for(int i=mid; i<mainArray.size(); i++)
                right[i-mid] = mainArray[i];
            mergesort(left);
            mergesort(right);
            merge(left, right, mainArray, left.size(), right.size());
        }
    int reversePairs(vector<int>& nums) {
        mergesort(nums);
        return count;
    }
};